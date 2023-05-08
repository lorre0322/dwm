#! /bin/bash
# DWM自启动脚本 仅作参考 
# 搭配 https://github.com/yaocccc/scripts 仓库使用 目录位置 ~/scripts
# 部分配置文件在 ~/scripts/config 目录下

_thisdir=$(cd $(dirname $0);pwd)

daemons() {
    [ $1 ] && sleep $1
    # picom --experimental-backends &
    picom  &
    feh --bg-fill ~/Desktop/dwm/wallpaper/03.jpg
    fcitx5 &
    $_thisdir/statusbar.sh cron &   # 开启状态栏定时更新
    mpd &
    dunst &
    sudo mongod -f /etc/mongodb.conf
}

cron() {
    [ $1 ] && sleep $1
    let i=10
    while true; do
        # [ $((i % 10)) -eq 0 ] && ~/scripts/set_screen.sh check # 每10秒检查显示器状态 以此自动设置显示器
        # [ $((i % 300)) -eq 0 ] && feh --randomize --bg-fill ~/Desktop/dwm/wallpaper/*.jpg # 每300秒更新壁纸
        sleep 10; let i+=10
    done
}
# 后台启动项
daemons 1 &
cron 1 &
