# cmmk (simple binary around libcmmk)

* Simple binary to set colors to keys on coolermaster keyboards
* See https://github.com/chmod222/libcmmk for the library that does the actual work

## Install (arch)

* pamac build libcmmk-git # Or any other aur package manager
* make && make install    # It ends up in ~/bin/cmmk

## Usage

* cmmk reset
  * Resets colors back to normal

* cmmk manual
  * Sets colors in manual mode so you can change them
  * Use reset to set it back

* cmmk single 4 7 255 0 0
  * Sets one key to red
  * Can be run multiple time to set other keys as well
  * 4 is the row, 7 is column, rest is R, G or B (0 to 255)

* cmmk all 0 200 200
  * Sets all leds to one color
  * You can use the single command after to change some of them..

## Building of libcmmk

* git clone https://github.com/chmod222/libcmmk.git
* cmake -DCMAKE_INSTALL_PREFIX=/usr .
* make && sudo make install