#! /bin/bash
# VOL 音量脚本
# 本脚本需要你自行修改音量获取命令
# 例如我使用的是 pipewire
#
# $ pactl list sinks | grep RUNNING -A 8
#         State: RUNNING
#         Name: bluez_output.88_C9_E8_14_2A_72.1
#         Description: WH-1000XM4
#         Driver: PipeWire
#         Sample Specification: float32le 2ch 48000Hz
#         Channel Map: front-left,front-right
#         Owner Module: 4294967295
# 静音 -> Mute: no                                                                                 
# 音量 -> Volume: front-left: 13183 /  20% / -41.79 dB,   front-right: 13183 /  20% / -41.79 dB

tempfile=$(cd $(dirname $0);cd ..;pwd)/temp

this=_voice
signal=$(echo "^s$this^" | sed 's/_//')

update() {
    muted=$(amixer get Master | grep off)
    vol_text=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
    if [ "$muted" ];      then vol_text="--"; vol_icon="󰝟";
    elif [ "$vol_text" -eq 0 ];  then vol_text="00"; vol_icon="";
    elif [ "$vol_text" -lt 10 ]; then vol_icon=""; vol_text=0$vol_text;
    elif [ "$vol_text" -le 50 ]; then vol_icon="󰕾";
    else vol_icon="󰕾"; fi

    icon=" $vol_icon"
    text=" $vol_text % "

    sed -i '/^export '$this'=.*$/d' $tempfile
    printf "export %s='%s%s%s%s%s'\n" $this "$signal" "$icon" "$text" >> $tempfile
}

notify() {
    update
    notify-send -r 9527 -h int:value:$vol_text -h string:hlcolor:#dddddd "Volume"
}

click() {
    case "$1" in
        L) pactl set-sink-mute @DEFAULT_SINK@ toggle;;
        R) killall pavucontrol || pavucontrol --class=FGN & ;; # 打开pavucontrol
        # U) amixer set Master 5%+ ;;
        # D) amixer set Master 5%- ;;
        U) pactl set-sink-volume @DEFAULT_SINK@ +5%; notify ;; # 音量加
        D) pactl set-sink-volume @DEFAULT_SINK@ -5%; notify ;; # 音量减
    esac
}

case "$1" in
    click) click $2 ;;
    notify) notify ;;
    *) update ;;
esac
