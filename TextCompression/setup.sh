chmod +x ./*
mkdir /home/$USER/sMALL
cp ./compress /home/$USER/sMALL/compress
cp ./decompress /home/$USER/sMALL/decompress
cd /home/$USER/sMALL
chmod +x compress 
chmod +x decompress
echo "alias compress='/home/"$USER"/sMALL/compress'" >> ~/.bashrc
echo "alias decompress='/home/"$USER"/sMALL/decompress'" >> ~/.bashrc
source ~/.bashrc

echo '--------------------------------------------------------------------------------------------------------------------'
echo 'Installation Successful'
echo 'Please restart the terminal or close the current terminal and open a new one to enable the application to run.'
echo '--------------------------------------------------------------------------------------------------------------------'
echo 'In case of bugs, please raise an issue on the git-hub repository [LINK] https://github.com/vs666/sMALL'
echo '--------------------------------------------------------------------------------------------------------------------'