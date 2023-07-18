#!/usr/bin/python3.9

import epics
import time
import argparse
import sys
from PIL import Image
import numpy as np
import os

PV_Prefixes = ["TEST-PCO:", "FLIR:"]

def acquire(PV_Prefix, saveImage):

    epics.PV("SingleShot:Interlock").put(1, wait=True)

    epics.PV(PV_Prefix + "cam1:ImageMode").put(0, wait=True)
    epics.PV(PV_Prefix + "cam1:NumImages").put(1, wait=True)
    camera_counter = epics.PV(PV_Prefix + "cam1:ArrayCounter_RBV").get()
    print("open exposure shutter...")
    epics.PV("I10EH-SHUTTER:command").put(1, wait=True)
    time.sleep(0.01)
    epics.PV(PV_Prefix + "cam1:Acquire").put(1, wait=True)
    print(camera_counter)
    while epics.PV(PV_Prefix + "cam1:ArrayCounter_RBV").get() == camera_counter: 
        pass
    print(epics.PV(PV_Prefix + "cam1:ArrayCounter_RBV").get())
    epics.PV("I10EH-SHUTTER:command").put(0, wait=True)
    print("close exposure shutter")
    time.sleep(0.01)

    if saveImage == "Y":
        reshaping(PV_Prefix) 
    else:
        epics.PV("SingleShot:Interlock").put(0, wait=True)
        print("image completed!")

def reshaping(PV_Prefix):

    x = epics.PV(PV_Prefix + "image1:ArrayData").get()
    sizeX = epics.PV(PV_Prefix + "cam1:ArraySizeX_RBV").get()
    sizeY = epics.PV(PV_Prefix + "cam1:ArraySizeY_RBV").get()
    
    # Reshape the array to 2D
    print(f"reshape image to {epics.PV(PV_Prefix + 'cam1:ArraySizeX_RBV').get()} X {epics.PV(PV_Prefix + 'cam1:ArraySizeY_RBV').get()}")
    reshapedArray = np.reshape(x, (sizeX, sizeY))
    print("image reshaped!")
    saveImage(reshapedArray)

def saveImage(reshapedArray):
    
    # Convert the array to an image
    imagePath, imageExtension = os.path.splitext(epics.PV("SingleShot:ImagePath").get(as_string=True))
    print(f"saving image to {imagePath}{imageExtension}")
    image = Image.fromarray(reshapedArray.astype(np.uint8))
    image.save(imagePath + imageExtension)
    epics.PV("SingleShot:Interlock").put(0, wait=True)
    print(f"image {imagePath}{imageExtension} saved!")


if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="BEATS ZMQ Writer")
    parser.add_argument('--detectorPVPrefix', type=str, help=' -> TEST-PCO:, FLIR:')
    parser.add_argument('--saveImage', type=str, default="No", help='-> Yes, No')

    args = parser.parse_args()
    detector = args.detectorPVPrefix
    save = args.saveImage
    
    if detector.upper() in PV_Prefixes:
        if detector.upper() == "TEST-PCO:":
            epics.PV(detector.upper() + "cam1:TriggerMode").put(1, wait=True)
            acquire(detector.upper(), save[0].capitalize())
        
        elif detector.upper() == "FLIR:":
            epics.PV(detector.upper() + "cam1:TriggerSource").put(0, wait=True)
            acquire(detector.upper(), save[0].capitalize())
        
    else:
        print(f"{detector} is not correct PV prefix!!!")
        sys.exit()
