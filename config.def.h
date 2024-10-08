/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#282828";
static char normbordercolor[]       = "#504945";
static char normfgcolor[]           = "#ebdbb2";
static char selfgcolor[]            = "#282828";
static char selbordercolor[]        = "#d79921";
static char selbgcolor[]            = "#d79921";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "nmtui", "-g", "120x34", "-e", "nmtui", NULL };
const char *spcmd3[] = {"st", "-n", "lf", "-g", "120x34", "-e", "lf", NULL };
const char *spcmd4[] = {"st", "-n", "htop", "-g", "120x34", "-e", "htop", NULL };
const char *spcmd5[] = {"st", "-n", "newsboat", "-g", "120x34", "-e", "newsboat", NULL };
const char *spcmd6[] = {"st", "-n", "ncmpcpp", "-g", "120x34", "-e", "ncmpcpp", NULL };
const char *spcmd7[] = {"st", "-n", "pulsemixer", "-g", "120x34", "-e", "pulsemixer", NULL };
static Sp scratchpads[] = {
        /* name          cmd  */
        {"spterm",      spcmd1},
        {"nmtui",      spcmd2},
        {"lf",      spcmd3},
        {"htop",      spcmd4},
        {"newsboat",      spcmd5},
        {"ncmpcpp",      spcmd6},
        {"pulsemixer",      spcmd7},
};

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
static const Rule rules[] = {
        /* class      instance    title       tags mask     isfloating   monitor */
        { "Gimp",     NULL,       NULL,       0,            1,           -1 },
        { "Firefox",  NULL,       NULL,       0,            0,           -1 },
        { NULL,           "spterm",             NULL,           SPTAG(0),               1,
                   -1 },
        { NULL,           "nmtui",              NULL,           SPTAG(1),               1,
                   -1 },
        { NULL,           "lf",                 NULL,           SPTAG(2),               1,
                   -1 },
        { NULL,           "htop",               NULL,           SPTAG(3),               1,
                   -1 },
        { NULL,           "newsboat",           NULL,           SPTAG(4),               1,
                   -1 },
        { NULL,           "ncmpcpp",            NULL,           SPTAG(5),               1,
                   -1 },
        { NULL,           "pulsemixer",         NULL,           SPTAG(6),               1,
                   -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	/*{ MODKEY,			XK_grave,	spawn,	SHCMD("dmenuunicode") } ,*/
	/*{ MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") },*/
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%-; kill -43 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -43 $(pidof dwmblocks)") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%+; kill -43 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -43 $(pidof dwmblocks)") },
	/*{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("sysact") },*/
	/*{ MODKEY|ShiftMask,		XK_BackSpace,	spawn,		SHCMD("sysact") },*/
	{ MODKEY,			XK_Tab,		view,		{0} },
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_q,		killclient,	{0} },
	{ MODKEY|ShiftMask,		XK_q,		spawn,		SHCMD("sysact") },
	{ MODKEY,			XK_w,		spawn,		SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,		XK_w,		togglescratch,	{.ui = 1} },
	/*{ MODKEY,			XK_e,		spawn,		SHCMD("st -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },*/
	/*{ MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD("st -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },*/
	{ MODKEY,			XK_r,		togglescratch,	{.ui = 2 } },
	{ MODKEY|ShiftMask,		XK_r,		togglescratch,	{.ui = 3} },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* monocle */
	{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[2]} }, /* bstack */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} }, /* bstackhoriz */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, /* centered master  */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} }, /* centered floating master  */
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,			spawn,		SHCMD("mpc toggle") },
	/*{ MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("mpc pause ; pauseallmpv") },*/
	{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("mpc seek -60") },
	{ MODKEY,			XK_bracketright,	spawn,		SHCMD("mpc seek +10") },
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("mpc seek +60") },
	/*{ MODKEY,			XK_backslash,		view,		{0} },*/
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	/* { MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_d,		spawn,          {.v = dmenucmd } },
	/* { MODKEY,			XK_d,		spawn,		SHCMD("") } }, */
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[6]} }, /* Float */
	/*{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },*/
	{ MODKEY|ShiftMask,		XK_j,		movestack,	{ .i = +1 } },
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.05} },
	/*{ MODKEY,			XK_semicolon,	movestack,	{ .i = 1 } },*/
	{ MODKEY|ShiftMask,		XK_k,		movestack,	{ .i = -1 } },
	{ MODKEY,			XK_apostrophe,	togglescratch,	{.ui = 0} },
	/* { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	/*{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },*/
	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY|ShiftMask,		XK_z,		incrigaps,	{.i = +3 } },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	{ MODKEY|ShiftMask,		XK_x,		incrigaps,	{.i = -3 } },
	{ MODKEY,			XK_c,		spawn,		SHCMD("xbacklight -inc 5;kill -44 $(pidof dwmblocks)") }, 
	{ MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("xbacklight -inc 10;kill -44 $(pidof dwmblocks)") }, 
	{ MODKEY,			XK_v,		spawn,		SHCMD("xbacklight -dec 5;kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_v,		spawn,		SHCMD("xbacklight -dec 10;kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_b,		togglebar,	{0} },
	/*{ MODKEY|ShiftMask,		XK_b,		togglescratch,		{.ui = 7} },*/
	{ MODKEY,			XK_n,		togglescratch,	{.ui = 5} },
	{ MODKEY|ShiftMask,		XK_n,		togglescratch,	{.ui = 4} },
	{ MODKEY,			XK_m,		spawn,		SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -43 $(pidof dwmblocks)") },
	/*{ MODKEY|ShiftMask,		XK_m,		togglescratch,	{.ui = 5} },*/
	{ MODKEY,			XK_e,		togglescratch,	{.ui = 6} },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc prev") },
	/*{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc seek 0%") },*/
	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc next") },
	/*{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc repeat") },*/

	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	/*{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },*/
	/*{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },*/
	/*{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },*/
	/*{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },*/
	/*{ MODKEY,			XK_Insert,	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },*/

	/*{ MODKEY,			XK_F1,		spawn,		SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },*/
	/*{ MODKEY,			XK_F2,		spawn,		SHCMD("tutorialvids") },*/
	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	/*{ MODKEY,			XK_F4,		spawn,		SHCMD("st -e pulsemixer; kill -44 $(pidof dwmblocks)") },*/
	/*{ MODKEY,			XK_F5,		xrdb,		{.v = NULL } },*/
	/*{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },*/
	/*{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },*/
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mailsync") },
	/*{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },*/
	/*{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },*/
	/*{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },*/
	/*{ MODKEY,			XK_F12,		xrdb,		{.v = NULL } },*/
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },

	{ 0,				XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
	{ MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -43 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%+; kill -43 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%-; kill -43 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD("st -e ncmpcpp") },
	{ 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") },
	/*{ 0, XF86XK_Calculator,		spawn,		SHCMD("st -e bc -l") },*/
	{ 0, XF86XK_Sleep,		spawn,		SHCMD("dpas zzz") },
	{ 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		spawn,		SHCMD("st") },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock") },
	{ 0, XF86XK_TaskPane,		spawn,		SHCMD("st -e htop") },
	/*{ 0, XF86XK_Mail,		spawn,		SHCMD("st -e neomutt ; pkill -RTMIN+12 dwmblocks") },*/
	/*{ 0, XF86XK_MyComputer,		spawn,		SHCMD("st -e lf /") },*/
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
	/*{ 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },*/
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15;kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15;kill -44 $(pidof dwmblocks)") },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

