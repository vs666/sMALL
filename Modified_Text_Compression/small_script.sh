filename=$2
opt=$1

if [[ $# -ge 3 || $# -eq 0 ]]
then
    echo "Error : Parameters incomplete..."
    exit 0
fi
if [ $opt == '-h' ]
then
    echo "Data Compression using RLE + Huffman."
    echo "small -c [file_to_compress]  -> for compression"
    echo "small -d   -> for decompression"
    echo "small -h   -> for help"
    exit 0
fi

if [ $opt == '-c' ]
then
    # code to compress the file
    /home/$USER/sMALL_v1.0/rle <<< $filename > ____op_file_tmp_101001.txt
    read -p 'Enter final filename (without extension) : ' finalfile
    /home/$USER/sMALL_v1.0/compress <<< $(echo "____op_file_tmp_101001.txt " $finalfile)
    rm ____op_file_tmp_101001.txt
else
if [ $opt == '-d' ]
then
    read -p 'Enter the filename of the metadata file : ' metadataFilename
    read -p 'Enter the filename of the compressed file : ' compressedFilename
    read -p 'Enter the filename of the decompressed file : ' decFilename
    /home/$USER/sMALL_v1.0/decompress <<< $(echo $metadataFilename " " $compressedFilename " ___decompressed.txt")
    /home/$USER/sMALL_v1.0/rld > $decFilename <<< "___decompressed.txt"
    rm ___decompressed.txt
    # code to decompress the file
fi
fi
