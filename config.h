/* See LICENSE file for copyright and license details. */

/* appearance */
<<<<<<< HEAD
static const unsigned int borderpx  = 1;        /* border pixel of windows */
=======
<<<<<<< HEAD
static const unsigned int borderpx  = 1;        /* border pixel of windows */
=======
<<<<<<< HEAD
static const unsigned int borderpx  = 1;        /* border pixel of windows */
=======
static const unsigned int borderpx  = 1;        /* 窗口边框大小 */
>>>>>>> 4f9b751 (💻My desktop window manager.)
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
static const unsigned int gappx     = 1;        /* gaps between windows */
static const unsigned int snap      = 1;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
static const unsigned int systraypinning = 5;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const Bool viewontag	    = True;     /* Switch View on tag switch */
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
static const int newclienway             = 1;        /* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: 选择显示的显示器, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: 如果固定失败，在第一个显示器显示任务栏, False: 在最后显示器显示*/
static const int showsystray             = 1;   /* 0 means no systray */
/* layout(s) */
static const float mfact     = 0.6; /* 窗口比例 */
static const int nmaster     = 1;   /* 主工作区 窗口数量 */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
/* overview */
static const int overviewgappi           = 24;        /* overview时 窗口与边缘 缝隙大小 */
static const int overviewgappo           = 60;        /* overview时 窗口与窗口 缝隙大小 */
static const char *overviewtag = " :) ";
static const Layout overviewlayout = { " :) ", overview };
/* commands */
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname , "-g", "120x34", NULL };
/* fonts & color */
>>>>>>> 4f9b751 (💻My desktop window manager.)
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
static const char *fonts[]          = { 
	"JetBrainsMono Nerd Font:size=16",
};
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#FFEBCD", "#2c3643", "#444444" },
	[SchemeSel]  = { "#2c3643", "#FFEBCD", "#cccccc"  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

/* launcher commands (They must be NULL terminated) */
static const char* fireGithub[]      = { "firefox", "https://github.com/lorre0322", NULL };
static const char* firefox[]      = { "firefox", NULL, NULL };

static const Launcher launchers[] = {
       /* command       name to display */
	{ fireGithub,   "Lorre" },
};

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";
/* tagging */
static const char *tags[] = { " ", "贰","叁","肆","伍","陆","柒","捌","玖" };

/* launcher commands (They must be NULL terminated) */
static const char* fireGithub[] = { "firefox", "https://github.com/lorre0322", NULL };
static const Launcher launchers[] = {
  /* command     name to display */
	{ fireGithub , "Lorre" },
};


/*  */
>>>>>>> 4f9b751 (💻My desktop window manager.)
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
static const Rule rules[] = {
	/* class		|instance	|title		|tags mask|isfloating| monitor */
	{ "netease-cloud-music"	, NULL		, NULL		, 0	 , 1	, -1	},
	{ "firefox"		, NULL		, NULL		, 0	 , 0	, -1	},
	{ NULL			, "wechat.exe"	, NULL		, 0	 , 1	, -1	},
};

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
/* layout(s) */
static const float mfact     = 0.55; /* 窗口比例 */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  ",      tile },    /* 平铺 */
	{ "  ",      NULL },    /* 窗口 */
	{ "-M-",      monocle },/* 单应用 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ﬿ ",      tile },         /* 平铺 */
  { " 﩯 ",      magicgrid },    /* 网格 */
>>>>>>> 4f9b751 (💻My desktop window manager.)
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
/* commands */
static const char *rofi[] ={"rofi","-show","drun",NULL};
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname , "-g", "120x34", NULL };
static const char *screenshot[] = { "deepin-screenshot", NULL };/* deepin-screenshot截图 */
/* 定义音量和亮度管理 */
static const char *voiceup[] = { "amixer" , "set" , "Master" , "5%+" , NULL };
static const char *voicedown[] = { "amixer" , "set" , "Master" , "5%-" , NULL };
static const char *voicetoggle[] = { "amixer" , "set" , "Master" , "toggle" , NULL };
/* 外接显示屏是适用 xrandr查看 */
static const char *xrandrdark[] = { "xrandr" , "--output" , "HDMI-0" , "--brightness" , "0.7" , NULL };
static const char *xrandrlight[] = { "xrandr" , "--output" , "HDMI-0" , "--brightness" , "0.9" , NULL };
static const char *xrandrfull[] = { "xrandr" , "--output" , "HDMI-0" , "--brightness" , "1" , NULL };
/* mpc音乐播放 */
static const char *mpctoggle[] = { "mpc" , "toggle" , NULL };
static const char *mpcprev[] = { "mpc" , "prev" , NULL };
static const char *mpcnext[] = { "mpc" , "next" , NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* 自定义打开应用 */
	{ MODKEY,                       XK_p,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_s,      spawn,          {.v = screenshot } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_c, 	   spawn,          {.v = firefox } },	
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },/* 临时终端 */
	/* 自定义音量管理按键 */
	{ MODKEY,                       XK_F11,	   spawn,          {.v = voicedown } },
	{ MODKEY,                       XK_F12,    spawn,          {.v = voiceup } },
	{ MODKEY|ShiftMask,             XK_F12,    spawn,          {.v = voicetoggle } },
	{ MODKEY,                       XK_F9, 	   spawn,          {.v = mpcprev } },
	{ MODKEY,                       XK_F10,    spawn,          {.v = mpcnext } },
	{ MODKEY|ShiftMask,             XK_F10,    spawn,          {.v = mpctoggle } },
	/* 自定义音乐播放 */
	{ MODKEY,                       XK_F7,	   spawn,          {.v = xrandrdark } },
	{ MODKEY,                       XK_F8,	   spawn,          {.v = xrandrlight } },
	{ MODKEY|ShiftMask,             XK_F8,	   spawn,          {.v = xrandrfull } },
	
	{ MODKEY,                       XK_b,      togglebar,      {0} },/* 隐藏顶栏 */
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },/* 切换窗口堆栈 */
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },/* 切换聚焦窗口 */
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, /* 改变横竖布局 */
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },/* 改变窗口比例 */
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },/* 第一二应用换位 */
	{ MODKEY,                       XK_Tab,    view,           {0} },/* 切换tag */
	{ MODKEY,                       XK_q,      killclient,     {0} },/* 关闭窗口 */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },/* 更换布局1 */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },/* 全屏 */
	{ MODKEY,                       XK_space,  setlayout,      {0} },/* 选择布局 */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },/* 切换浮动 */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },/* 跳转到1-9标签 */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },/* 把应用放到1-9标签*/
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,   rotatetags,     {.i = -1 } },/* 左右切换tag */
	{ MODKEY,                       XK_Right,  rotatetags,     {.i = +1 } },
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* 布局设置 */
	{ MODKEY,           XK_b,      togglebar,      {0} },/* 隐藏顶栏 */
	{ MODKEY|ShiftMask, XK_j,      rotatestack,    {.i = +1 } },/* 切换窗口堆栈 */
	{ MODKEY|ShiftMask, XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,           XK_j,      focusstack,     {.i = +1 } },/* 切换聚焦窗口 */
	{ MODKEY,           XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,           XK_e,      incnmaster,     {.i = +1 } }, /* 改变横竖布局 */
	{ MODKEY,           XK_comma,  setmfact,       {.f = -0.05} },/* 改变窗口比例 */
	{ MODKEY,           XK_period, setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return, zoom,           {0} },/* 第一二应用换位 */
	{ MODKEY,           XK_Tab,    view,           {0} },/* 切换tag */
	{ MODKEY,           XK_q,      killclient,     {0} },/* 关闭窗口 */
	{ MODKEY|ShiftMask, XK_f,      fullscreen,     {0} },/* 全屏 */
	{ MODKEY,           XK_space,  setlayout,      {0} },/* 选择布局 */
	{ MODKEY|ShiftMask, XK_space,  togglefloating, {0} },/* 切换浮动 */
	{ MODKEY,           XK_0,      view,           {.ui = ~0 } },/* 跳转到1-9标签 */
	{ MODKEY|ShiftMask, XK_0,      tag,            {.ui = ~0 } },/* 把应用放到1-9标签*/
	{ MODKEY,           XK_Left,   rotatetags,     {.i = -1 } },/* 左右切换tag */ 
	{ MODKEY,           XK_Right,  rotatetags,     {.i = +1 } },
	{ MODKEY,           XK_t,      setlayout,      {.v = &layouts[0]} },/* 更换布局1 */
	{ MODKEY,           XK_f,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,           XK_a,      toggleoverview, {0} }, /* 显示所有tag 或 跳转到聚焦窗口的tag */

	/* 自定义打开应用 SHCMD("")*/
	{ MODKEY,           XK_p,      spawn,          SHCMD("rofi -show drun") },
	{ MODKEY,           XK_s,      spawn,          SHCMD("deepin-screenshot") },
	{ MODKEY|ShiftMask, XK_Return, spawn,          SHCMD("st") },
	{ MODKEY,           XK_c, 	   spawn,          SHCMD("firefox") },	
	{ MODKEY,           XK_grave,  togglescratch,  {.v = scratchpadcmd} },/* 临时终端 */


	/* 自定义音量管理按键 */
	{ MODKEY,           XK_F11,	   spawn,          SHCMD("amixer set Master 5%-") },
	{ MODKEY,           XK_F12,    spawn,          SHCMD("amixer set Master 5%+") },
	{ MODKEY|ShiftMask,	XK_F12,    spawn,          SHCMD("amixer set Master toggle") },
	{ MODKEY,           XK_F9, 	   spawn,          SHCMD("mpc prev") },
	{ MODKEY,           XK_F10,    spawn,          SHCMD("mpc next") },
	{ MODKEY|ShiftMask, XK_F10,    spawn,          SHCMD("mpc toggle") },
	/* 自定义音乐播放 */
	{ MODKEY,           XK_F7,	   spawn,          SHCMD("xrandr --output HDMI-0 --brightness 0.7") },
	{ MODKEY,           XK_F8,	   spawn,          SHCMD("xrandr --output HDMI-0 --brightness 0.9") },
	{ MODKEY|ShiftMask, XK_F8,	   spawn,          SHCMD("xrandr --output HDMI-0 --brightness 1") },

>>>>>>> 4f9b751 (💻My desktop window manager.)
>>>>>>> 8d4e335 (💻My desktop window manager.)
>>>>>>> 302231c (💻My desktop window manager.)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },/* 按两次退出dwm */
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, /* 按两次重启刷新dwm */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	/* 给dwmblocks传递 1>点击 2>按滚轮 3>右击 45>滑动滚轮 */
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,      Button2,        sigstatusbar,   {.i = 7} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

