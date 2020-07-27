chmod +x ./*
mkdir /home/$USER/sMALL_v1.0
cp ./compress /home/$USER/sMALL_v1.0/compress
cp ./small_script.sh /home/$USER/sMALL_v1.0/small_script.sh
cp ./decompress /home/$USER/sMALL_v1.0/decompress
cp ./rle /home/$USER/sMALL_v1.0/rle
cp ./rld /home/$USER/sMALL_v1.0/rld
cd /home/$USER/sMALL_v1.0
chmod +x compress 
chmod +x decompress
echo "alias small='/home/"$USER"/sMALL_v1.0/small_script.sh'" >> ~/.bashrc
# echo "alias decompress='/home/"$USER"/sMALL_v1.0/decompress'" >> ~/.bashrc
source ~/.bashrc

echo '--------------------------------------------------------------------------------------------------------------------'
echo 'Installation Successful'
echo 'Please restart the terminal or close the current terminal and open a new one to enable the application to run.'
echo '--------------------------------------------------------------------------------------------------------------------'
echo 'In case of bugs, please raise an issue on the git-hub repository https://github.com/vs666/sMALL'
echo '--------------------------------------------------------------------------------------------------------------------'