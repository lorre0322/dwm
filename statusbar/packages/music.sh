#! /bin/bash
# MEM

tempfile=$(cd $(dirname $0);cd ..;pwd)/temp

this=_music
signal=$(echo "^s$this^" | sed 's/_//')

# /^volume:/d;s/\\&/&amp;/g;s/\\[paused\\].*/奈/g;/\\[playing\\].*/d
filter(){ mpc | sed "/^volume:/d;s//&/g;s/\\[paused\\].*//g;/\\[playing\\].*/d" | paste -sd ' '; }
update() {
	music_icon="󰝚"
    music_text=$(mpc status | filter)
    icon=" $music_icon"
    text=" $music_text  "

    sed -i '/^export '$this'=.*$/d' $tempfile
    printf "export %s='%s%s%s%s%s'\n" $this "$signal" "$icon" "$text" >> $tempfile
}

notify() {
    notify-send "Now playing" "$(mpc status | filter)" -r 9527
}

call_ncmpcpp() {
    pid1=`ps aux | grep 'st -t statusutil' | grep -v grep | awk '{print $2}'`
    pid2=`ps aux | grep 'st -t statusutil_music' | grep -v grep | awk '{print $2}'`
    mx=`xdotool getmouselocation --shell | grep X= | sed 's/X=//'`
    my=`xdotool getmouselocation --shell | grep Y= | sed 's/Y=//'`
    kill $pid1 && kill $pid2 || st -t statusutil_music -g 40x9+$((mx + 2))+$((my + 20)) -c FGN -e ncmpcpp
}

click() {
    case "$1" in
        L) mpc toggle | filter | notify ;; 
        M) mpc listall | mpc del | mpc add ; notify-send "   歌单已刷新~" ;;
        # R) sudo setsid -f st -e ncmpcpp ;;
        R) call_ncmpcpp ;;
        U) mpc prev | filter | notify ;;
        D) mpc next | filter | notify ;;
    esac
}

case "$1" in
    click) click $2 ;;
    notify) notify ;;
    *) update ;;
esac
