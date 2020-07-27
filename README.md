# sMALL
Makes files smaller, to accomodate more files...

This repository is an attempt for developing a command-line compression platform.

## 1. Huffman Compression for text files

This code will compress the text files using huffman compression, create a compressed text file as-well-as a metadata file.
We would need the text file as well as the metadata file for the decompression of the files.

The compression rate is around 50% on an average and metadata file size is always under 1Kb

To install 
```bash
git clone https://github.com/vs666/sMALL.git
cd sMALL
chmod +x setup.sh
./setup.sh
```
To use
```bash
compress
decompress
```
for compression and decompression respectively

### In case of any issue please raise an issue on this repository

## 2. Modified Huffman Compression for text files
Modified Text Compression
This algorithm uses Run-Length-Encoding followed by Static-Huffman-Compression
To install, goto Modified_Text_Compression
then,
```bash
./setup.sh
```
To use :
for options to use
```bash
small -h
```
for compression,
```bash
small -c [filename]
```

for decompression
```bash
small -d
```


## 3. Arithmetic Compression for text files

This code will use arithmetic compression, which is expected to have a better compression rate than huffman.
Other than that, the basic structure of this application will be similar to that of Huffman.
This code is also under production.
