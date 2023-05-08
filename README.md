


## 安装依赖
```bash
# 美化
sudo pacman -S  breeze-gtk papirus-icon-theme ttf-jetbrains-mono-nerd
# 截图 剪贴板
sudo pacman -S deepin-screenshot gpaste
# u盘识别
sudo pacman -S udisks2 gvfs
```

## 修改文件
```bash
// 把dwm位置写入.bashrc
echo "export DWM=/home/lorre/Deskdtop/dwm" >> .bashrc
echo "export DWM=/home/lorre/Deskdtop/dwm" >> .profile
```

## 安装dwm
```bash
sudo make clean install
// 如若没有权限
sudo chmod 777 /path
```

## aria2下载
```bash
# 安装
sudo padman -S aria2
# 指令
aria2c
–max-download-limit http://download.zip    # 限制最大下载速度
-o rename.zip http://download.zip   # 初始化下载文件
-c http://download.zip    # 使用-c时可以继传
-i http://download.txt    # 可以讲每一个url储存在单独的行中
aria2c --conf-path=/home/lorre/.config/aria2/aria2.conf    # 根据配置文件启动aria2
```
