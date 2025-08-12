# pl-880_mods_backlight_and_bluetooth
Modifications for the SW Radio Tecsun PL-880: RGB Backlight and Bluetooth audio

# PL-880 RGB Backlight mod
As i find the orange backlight a bit not comfortable specially when there is no other light around, I gave it a try and changed it to pure red. Could have replaced the LED but instead I used a microcontroller and an RGB LED (a section f one LED taken from and RGB LED strip). 
So technically i can now program it to display any RGB color as well changing the brightness!

# PL-880 Bluetooth Audio mod
The simplest approach for me was to dismantle an  existing 2-in-1 TX/RX Bluetooth module, remove its audio jack and  battery, and wire it directly to the radio's main board. I then secured  the module between the radio's board and the rear plastic cover. A small  hole drilled in the back cover, hidden behind the support flap,  provides access to the module's power button.
The result is excellent: even FM reception is now in clear, loud stereo – all internally! I may document this project on GitHub.
One  current limitation is unreliable connection with my Bluetooth speaker  (it disconnects after 1-2 seconds). However, it works perfectly with my Bluetooth headphones. I haven't tested other BT devices yet, but this  serves as a proof of concept

For further details please check the PDF file.
