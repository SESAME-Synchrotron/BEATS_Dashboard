#!/usr/bin/python3.9

import os
import sys
import time
import argparse
import numpy as np
from PIL import Image
from epics import PV

timeout = 1
PV_Prefixes = ["TEST-PCO:", "FLIR:"]

interlockPV = "SingleShot:Interlock"
imageModePV = "cam1:ImageMode"
numImagesPV = "cam1:NumImages"
arrayCounterPV = "cam1:ArrayCounter_RBV"
exposureShutterPV = "I10EH-SHUTTER:command"
acquirePV = "cam1:Acquire"
arrayDataPV = "image1:ArrayData"
sizeX_PV, sizeY_PV = "cam1:ArraySizeX_RBV", "cam1:ArraySizeY_RBV"
imagePathPV = "SingleShot:ImagePath"
enableCallbackPV = "image1:EnableCallbacks"
arrayCallbackPV = "image1:ArrayCallbacks"
triggerModePV = "cam1:TriggerMode"
triggerSourcePV = "cam1:TriggerSource"

def acquire(PV_Prefix, saveImage):
    """
    Acquire:
    - interlock
    - set image mode ==> single
    - set #images ==> 1
    - open exposure shutter
    - acquire image and wait acquiring done
    - close exposure shutter
    - save image
    """

    PV(interlockPV).put(1, wait=True)

    PV(PV_Prefix + imageModePV).put(0, wait=True)
    PV(PV_Prefix + numImagesPV).put(1, wait=True)
    cameraCounter = PV(PV_Prefix + arrayCounterPV).get(timeout=timeout, use_monitor=False)

    print("open exposure shutter...")
    PV(exposureShutterPV).put(1, wait=True)
    time.sleep(0.05)

    PV(PV_Prefix + acquirePV).put(1, wait=True)
    print(cameraCounter)
    while PV(PV_Prefix + arrayCounterPV).get(timeout=timeout, use_monitor=False) == cameraCounter:
        time.sleep(0.01)
    print(PV(PV_Prefix + arrayCounterPV).get(timeout=timeout, use_monitor=False))

    print("close exposure shutter ...")
    PV(exposureShutterPV).put(0, wait=True)
    time.sleep(0.05)

    if saveImage == "Y":
        reshape(PV_Prefix)
    else:
        PV(interlockPV).put(0, wait=True)
        print("image completed!")

def reshape(PV_Prefix):
    """
    Reshape:
    - reshape the arrayData (1D) to the specified dimensions (2D)
    - save image
    """

    image = PV(PV_Prefix + arrayDataPV).get(timeout=timeout, use_monitor=False)
    sizeX = PV(PV_Prefix + sizeX_PV).get(timeout=timeout, use_monitor=False)
    sizeY = PV(PV_Prefix + sizeY_PV).get(timeout=timeout, use_monitor=False)

    print(f"reshaping image to {sizeX} X {sizeY}")
    try:
        reshapedArray = np.reshape(image, (sizeY, sizeX))
        print("image has been reshaped!")
    except:
        print("Couldn't reshape the image, please check the image dimensions!")
        PV(interlockPV).put(0, wait=True)
        sys.exit()

    save(reshapedArray)

def save(reshapedArray):
    """
    Save:
    - save the reshaped array as image
    """

    imagePath, imageExtension = os.path.splitext(PV(imagePathPV).get(as_string=True, timeout=timeout, use_monitor=False))
    image = Image.fromarray(reshapedArray)

    print(f"saving image to {imagePath}{imageExtension}")
    try:
        image.save(imagePath + imageExtension)
        print(f"image {imagePath}{imageExtension} has been saved!")
    except:
        print("Couldn't save the image, please check the image path!")
        PV(interlockPV).put(0, wait=True)
        sys.exit()

    PV(interlockPV).put(0, wait=True)


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Single Frame Acquisition")
    parser.add_argument('--detectorPVPrefix', type=str, help=' -> TEST-PCO:, FLIR:')
    parser.add_argument('--saveImage', type=str, default="No", help=' -> Yes, No')

    args = parser.parse_args()
    detector = args.detectorPVPrefix
    saving = args.saveImage

    if detector.upper() in PV_Prefixes:
        PV(detector.upper() + enableCallbackPV).put(1, wait=True)
        PV(detector.upper() + arrayCallbackPV).put(1, wait=True)

        if detector.upper() == "TEST-PCO:":
            PV(detector.upper() + triggerModePV).put(1, wait=True)
            acquire(detector.upper(), saving[0].capitalize())

        elif detector.upper() == "FLIR:":
            PV(detector.upper() + triggerSourcePV).put(0, wait=True)
            acquire(detector.upper(), saving[0].capitalize())

    else:
        print(f"{detector} is not correct PV prefix!!!")
        sys.exit()
