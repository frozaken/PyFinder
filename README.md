# PyFinder
A short command line tool to find python package dependancies in your python propjects
To install it:
```bash
mkdir build
cd build
cmake ..
make
sudo make install
```
To run it
```bash
pyfinder *.py > requirements.txt
pip install -r requirements.txt
```
Currently it will break on libraries with different import names than their pypi names
