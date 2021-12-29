import sleep
import requests

import RPi.GPIO as GPIO

SERVER_URL = "http://ajfjf:8000"

ARMED = True

STARTED_BOX_WORDS = False
FINISHED_BOX_WORDS = False
PLAYED_BOX_THANK_YOU = False

SONG_LENGTH = 100

BOX_PICKED_UP_PIN = 1
OPEN_BOX_PIN = 2

GPIO.setup(BOX_PICKED_UP_PIN, GPIO.IN)
GPIO.setup(OPEN_BOX_PIN, GPIO.OUT, 0)

def go():
    while True:
        r = requests.get(f"{SERVER_URL}/armed")
        if r.text == "true":
            ARMED = True
        else:
            ARMED = False

        if ARMED:
            if box_picked_up() and not STARTED_BOX_WORDS:
                play_box_words()
            if box_put_down() and FINISHED_BOX_WORDS:
                play_box_thank_you()
                break
        sleep(0.1)
    
    start_dreamer_song()
    sleep(SONG_LENGTH)
    open_box()
    sleep(5)
    start_can_song()

def box_picked_up():
    return GPIO.input(BOX_PICKED_UP_PIN)

def play_box_words():
    PLAYED_BOX_WORDS = True
    # play the words
    FINISHED_BOX_WORDS = True

def play_box_thank_you():
    pass
    # play box thank you message

def start_dreamer_song()
    requests.get(f"{SERVER_URL}/set_play_song")

def open_box():
    GPIO.output(OPEN_BOX_PIN, 1)

def start_can_song():
    # todo: PLAY THE SONG LOCALLY

def main():
    try:
        go()
    finally:
        GPIO.cleanup()