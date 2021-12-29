import sleep
import requests

SERVER_URL = "http://ajfjf:8000"

def go():
    while True:
        r = requests.get(f"{SERVER_URL}/status")
        if r.text == "PLAY_SONG":
            break
        sleep(0.1)
    
    # play the song
    print("PLAYING THE SONG")