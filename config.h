#include <X11/XF86keysym.h>
// 是否显示托盘
static int showsystray                    = 1;
// 新窗口是在栈顶还是栈底
static const int newclientathead          = 0;
// 窗口边框大小
static const unsigned int borderpx        = 2;
// 托盘跟随的显示器 0代表不指定
static const unsigned int systraypinning  = 0;
// 托盘 | 状态栏 间距
static const unsigned int systrayspacing  = 0;
static const unsigned int systrayspadding = 0;
// 窗口与窗口 缝隙大小 | 默认大小
static int gappi                 = 0;  
static int gappo                 = 0;
static const int _gappo          = 0;
static const int _gappi          = 0;
// 状态栏边距
static const int vertpad         = 0;
static const int sidepad         = 0;
// overview时 窗口与边缘 缝隙大小        
static const int overviewgappi   = 24;
static const int overviewgappo   = 60;
// 状态栏 是否显示 | 状态栏位置 0 1
static const int showbar         = 1; 
static const int topbar          = 1;
// 主工作区 比例 | 窗口数量
static const float mfact         = 0.6;
static const int   nmaster       = 1;
// 边缘依附宽度
static const unsigned int snap   = 10;
static const char *fonts[]       = { "JetBrainsMono Nerd Font:size=16"};
static const char *colors[][3]   = {
  // 颜色设置           ColFg      ColBg      ColBorder
  [SchemeNorm] =      { "#c6d0f5", "#292C3C", NULL      },
  [SchemeSel] =       { "#c6d0f5", "#51576d", "#737994" },
  [SchemeSelGlobal] = { NULL     , "#737994", "#A6D189" },
  [SchemeHid] =       { "#c6d0f5", "#292C3C", NULL      },
  [SchemeSystray] =   { NULL     , "#292C3C", NULL      },
  [SchemeUnderline] = { "#A6D189", NULL     , NULL      }, 
  [SchemeNormTag] =   { "#BABBF1", "#292C3C", NULL      },
  [SchemeSelTag] =    { "#c6d0f5", "#51576d", NULL      },
  [SchemeBarEmpty] =  { NULL     , "#292C3C", NULL      },
};
// 透明度
static const unsigned int baralpha       = 0xc0;
static const unsigned int borderalpha    = 0xdd;
static const unsigned int alphas[][3]    = {
  [SchemeNorm] = { OPAQUE, baralpha, borderalpha }, 
  [SchemeSel] = { OPAQUE, baralpha, borderalpha },
  [SchemeSelGlobal] = { OPAQUE, baralpha, borderalpha },
  [SchemeHid] = { OPAQUE, baralpha, borderalpha },
  [SchemeNormTag] = { OPAQUE, baralpha, borderalpha }, 
  [SchemeSelTag] = { OPAQUE, baralpha, borderalpha },
  [SchemeBarEmpty] = { OPAQUE, baralpha, borderalpha },
  
};

// 自定义脚本位置 自启动 | 状态栏
static const char *autostartscript = "$DWM/statusbar/autostart.sh";
static const char *statusbarscript = "$DWM/statusbar/statusbar.sh";

// 自定义 scratchpad instance
static const char scratchpadname[] = "scratchpad";

static const char *overviewtag = ":)";
static const Layout overviewlayout = { " ",  overview };

// 自定义布局
static const Layout layouts[] = {
	{ "󰾍 ", tile },    //主次栈
  { "󰕰 ",  magicgrid },    // 网格
};

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG, cmd) \
    { MODKEY,              KEY, view,       {.ui = 1 << TAG, .v = cmd} }, \
    { MODKEY|ShiftMask,    KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,  KEY, toggleview, {.ui = 1 << TAG} }, \

static Key keys[] = {
  // modifier            key           function          argument
  { MODKEY,              XK_F1,        togglesystray,    {0} },
  // 切换聚焦窗口
  { MODKEY,              XK_j,         focusstack,       {.i = +1} },
  { MODKEY,              XK_k,         focusstack,       {.i = -1} },
  // 本窗口左右tag移动
  { MODKEY|ShiftMask,    XK_j,         tagtoleft,        {0} },
  { MODKEY|ShiftMask,    XK_k,         tagtoright,       {0} },
  // 显示所所有tag的窗口
  { MODKEY,              XK_a,         toggleoverview,   {0} },
  // 主工作区比例
  { MODKEY,              XK_comma,     setmfact,         {.f = -0.05} },
  { MODKEY,              XK_period,    setmfact,         {.f = +0.05} },
  // 隐藏窗口
  { MODKEY,              XK_h,         hidewin,          {0} },
  { MODKEY|ShiftMask,    XK_h,         restorewin,       {0} },
  // 设置为主窗口
  { MODKEY,              XK_Return,    zoom,             {0} },
  // 切换浮动 单个 | 所有
  { MODKEY,              XK_t,         togglefloating,   {0} },
  { MODKEY|ShiftMask,    XK_t,         toggleallfloating,{0} },
  // 全屏
  { MODKEY,              XK_f,         fullscreen,       {0} },
  // 状态栏
  { MODKEY,              XK_b,         togglebar,        {0} },
  // 全局标记窗口
  { MODKEY,              XK_g,         toggleglobal,     {0} },
  // 关闭边框
  { MODKEY,              XK_u,         toggleborder,     {0} },
  // 主区域窗口数量
  { MODKEY,              XK_w,         incnmaster,       {.i = +1} },
  // 光标移动到另一显示器
  { MODKEY,              XK_b,         focusmon,         {.i = +1} },
  // 聚焦窗口移动到另一显示器
  { MODKEY|ShiftMask,    XK_b,         tagmon,           {.i = +1} },
  // 关闭 | 强制关闭 窗口
  { MODKEY,              XK_q,         killclient,       {0} },
  { MODKEY|ControlMask,  XK_q,         forcekillclient,  {0} },
  // 退出dwm
  { MODKEY|ControlMask,  XK_F12,       quit,             {0} },
  { MODKEY,              XK_space,     setlayout,        {0} },
  // 切换只显示一个窗口
  { MODKEY,              XK_n,         showonlyorall,    {0} },
  // 窗口间隙 增加 | 减少 | 重置
  { MODKEY|ControlMask,  XK_equal,     setgap,           {.i = -5} },
  { MODKEY|ControlMask,  XK_minus,     setgap,           {.i = +5} },
  { MODKEY|ControlMask,  XK_space,     setgap,           {.i = 0} },
  // 移动窗口
  { MODKEY|ControlMask,  XK_Up,        movewin,          {.ui = UP} },
  { MODKEY|ControlMask,  XK_Down,      movewin,          {.ui = DOWN} },
  { MODKEY|ControlMask,  XK_Left,      movewin,          {.ui = LEFT} },
  { MODKEY|ControlMask,  XK_Right,     movewin,          {.ui = RIGHT} },
  // 调整窗口
  { MODKEY|Mod1Mask,     XK_Up,        resizewin,        {.ui = V_REDUCE} },
  { MODKEY|Mod1Mask,     XK_Down,      resizewin,        {.ui = V_EXPAND} },
  { MODKEY|Mod1Mask,     XK_Left,      resizewin,        {.ui = H_REDUCE} },
  { MODKEY|Mod1Mask,     XK_Right,     resizewin,        {.ui = H_EXPAND} },
//XK_bracketleft
  // spawn + SHCMD 执行对应命令
  { MODKEY,              XK_grave,     togglescratch,  SHCMD("st -t scratchpad -g 100x28") },
  { MODKEY|ShiftMask,    XK_Return,    spawn,          SHCMD("st") },
  { MODKEY,              XK_p,         spawn,          SHCMD("rofi -show drun") },
  { MODKEY,              XK_e,         spawn,          SHCMD("thunar") },
  { MODKEY,              XK_c,         spawn,          SHCMD("/opt/microsoft/msedge/microsoft-edge") },
  { MODKEY,              XK_s,         spawn,          SHCMD("deepin-screenshot") },
  // 自定义命令 音量 | 音乐 | 亮度
  { MODKEY,              XK_equal,     spawn,          SHCMD("amixer set Master 5%+") },
  { MODKEY,              XK_minus,     spawn,          SHCMD("amixer set Master 5%-") },
  { MODKEY|ShiftMask,    XK_equal,     spawn,          SHCMD("amixer set Master toggle") },
  { MODKEY,              XK_9, 	       spawn,          SHCMD("mpc prev") },
  { MODKEY,              XK_0,         spawn,          SHCMD("mpc next") },
  { MODKEY|ShiftMask,    XK_0,         spawn,          SHCMD("mpc toggle") },
  { MODKEY,              XK_6, 	       spawn,          SHCMD("xrandr --output HDMI-0 --brightness 0.8") },
  { MODKEY,              XK_7,         spawn,          SHCMD("xrandr --output HDMI-0 --brightness 1") },
  { MODKEY,              XK_8,         spawn,          SHCMD("xrandr --output HDMI-0 --brightness 1.1") },

  // super key : 跳转到对应tag (可附加一条命令 若目标目录无窗口，则执行该命令)
  // super shift key : 将聚焦窗口移动到对应tag
  // key tag cmd 
  TAGKEYS(XK_1, 0, 0)
  TAGKEYS(XK_2, 1, 0)
  TAGKEYS(XK_y, 2, "firefox")
  TAGKEYS(XK_u, 3, "code")
  TAGKEYS(XK_i, 4, 0)
  TAGKEYS(XK_o, 5, 0)
};

static const char *tags[] = { "󰟀","󰝚","󰌀","󰅯","󰙴","󰄄" };

static const Rule rules[] = {
  // 定位窗口规则                                                 tag规则       是否浮动    全局浮动    边框       显示器  显示位置(九宫格)
  // class                instance              title             tags mask     isfloating  isglobal    isnoborder monitor floatposition
  { NULL,                 NULL,                "图片查看器",      0,            1,          0,          0,        -1,      0},
  { NULL,                 NULL,                "图片查看",        0,            1,          0,          0,        -1,      0},
  // 普通优先度
  { "firefox",            NULL,                 NULL,             1 << 2,       0,          0,          0,        -1,      0},
  { "code",               NULL,                 NULL,             1 << 3,       0,          0,          1,        -1,      0},
  { "obs",                NULL,                 NULL,             0,            0,          0,          1,        -1,      0},
  { NULL,                 "qq",                 NULL,             1 << 5,       0,          0,          1,        -1,      0},
  { "WeChat.exe",         NULL,                 NULL,             1 << 5,       1,          0,          1,        -1,      5},
  { "scratchpad",         "scratchpad",         "scratchpad",     TAGMASK,      1,          1,          0,        -1,      0},
  { "thunar",             "thunar",             NULL,             0,            1,          0,          1,        -1,      5},
  { "wemeetapp",          NULL,                 NULL,             TAGMASK,      1,          0,          0,        -1,      0},
  // 部分特殊class的规则  
  { "float",              NULL,                 NULL,             0,            1,          0,          0,        -1,      0}, // class = float       浮动
  { "global",             NULL,                 NULL,             TAGMASK,      0,          1,          0,        -1,      0}, // class = gloabl      全局
  { "noborder",           NULL,                 NULL,             0,            0,          0,          1,        -1,      0}, // class = noborder    无边框
  { "FGN",                NULL,                 NULL,             TAGMASK,      1,          1,          1,        -1,      0}, // class = FGN         浮动、全局、无边框
  { "FG",                 NULL,                 NULL,             TAGMASK,      1,          1,          0,        -1,      0}, // class = FG          浮动、全局
  { "FN",                 NULL,                 NULL,             0,            1,          0,          1,        -1,      0}, // class = FN          浮动、无边框
  { "GN",                 NULL,                 NULL,             TAGMASK,      0,          1,          1,        -1,      0}, // CLASS = GN          全局、无边框
  // 优先度低 越在上面优先度越低
  { NULL,                 NULL,                "crx_",            0,            1,          0,          0,        -1,      0}, // 错误载入时 会有crx_ 浮动
  { NULL,                 NULL,                "broken",          0,            1,          0,          0,        -1,      0}, // 错误载入时 会有broken 浮动
};

static Button buttons[] = {
  // click               event mask       button            function       argument 
  { ClkLtSymbol,          0,              Button1,          setlayout,     {0} },
  // 点击窗口标题栏操作 隐藏 | 切换 窗口
  { ClkWinTitle,         0,               Button1,          hideotherwins, {0} },
  { ClkWinTitle,         0,               Button3,          togglewin,     {0} },
  // 点击窗口操作 移动窗口 | 拖动窗口大小
  { ClkClientWin,        MODKEY,          Button1,          movemouse,     {0} },
  { ClkClientWin,        MODKEY,          Button3,          resizemouse,   {0} },
  // 点击tag操作 左中右滚轮
  { ClkTagBar,           0,               Button1,          view,          {0} },
  { ClkTagBar,           0,               Button3,          toggleview,    {0} },
  { ClkTagBar,           MODKEY,          Button1,          tag,           {0} },
  { ClkTagBar,           0,               Button4,          viewtoleft,    {0} },
  { ClkTagBar,           0,               Button5,          viewtoright,   {0} },
  // 点击状态栏操作
  { ClkStatusText,       0,               Button1,          clickstatusbar,{0} },
  { ClkStatusText,       0,               Button2,          clickstatusbar,{0} },
  { ClkStatusText,       0,               Button3,          clickstatusbar,{0} },
  { ClkStatusText,       0,               Button4,          clickstatusbar,{0} },
  { ClkStatusText,       0,               Button5,          clickstatusbar,{0} },
  // 点击bar空白处
  { ClkBarEmpty,         0,               Button1,          spawn, SHCMD("rofi -show window") },
  { ClkBarEmpty,         0,               Button3,          spawn, SHCMD("rofi -show drun") },
};
