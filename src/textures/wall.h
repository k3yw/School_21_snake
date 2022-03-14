#ifndef SRC_TEXTURES_WALL_H_
#define SRC_TEXTURES_WALL_H_


#define Q_BLOCK1 "╔"
#define W_BLOCK1 "═"
#define E_BLOCK1 "╗"
#define A_BLOCK1 "║"
#define S_BLOCK1 "░"
#define Z_BLOCK1 "╚"
#define C_BLOCK1 "╝"

#define Q_BLOCK_B_F "╭"
#define W_BLOCK_B_F "─"
#define E_BLOCK_B_F "╮"
#define A_BLOCK_B_F "│"
#define S_BLOCK_B_F " "

#define Q_BLOCK_B_S "╭"
#define W_BLOCK_B_S "─"
#define E_BLOCK_B_S "╮"
#define A_BLOCK_B_S "│"
#define S_BLOCK_B_S " "

#define Q_BLOCK_DWN "╭ "
#define W_BLOCK_DWN "─"
#define E_BLOCK_DWN "╮"
#define A_BLOCK_DWN "│"
#define S_BLOCK_DWN " "

#define Q_BLOCK_LF "╮"
#define W_BLOCK_LF "─"
#define E_BLOCK_LF "╯"
#define A_BLOCK_LF "│"
#define S_BLOCK_LF " "

#define Q_BLOCK_RT "╭"
#define W_BLOCK_RT "─"
#define E_BLOCK_RT "╰"
#define A_BLOCK_RT "│"
#define S_BLOCK_RT " "

#define Q_BLOCK_UP "╰"
#define W_BLOCK_UP "─"
#define E_BLOCK_UP "╯"
#define A_BLOCK_UP "│"
#define S_BLOCK_UP " "


#define Q_BLOCK_COIN "╭"
#define W_BLOCK_COIN "─"
#define E_BLOCK_COIN "╮"
#define A_BLOCK_COIN "│"
#define S_BLOCK_COIN ""
#define Z_BLOCK_COIN "╰"
#define C_BLOCK_COIN "╯"

#define Q_BLOCK_GOLOVA "╭"
#define W_BLOCK_GOLOVA "∆"
#define E_BLOCK_GOLOVA "╮"
#define A_BLOCK_GOLOVA "│"
#define S_BLOCK_GOLOVA " "

#define Q_BLOCK_VN " "
#define W_BLOCK_VN "V"
#define E_BLOCK_VN "╯"
#define A_BLOCK_VN "│"
#define S_BLOCK_VN "╰"

#define Q_BLOCK_GP "╯"
#define W_BLOCK_GP "─"
#define E_BLOCK_GP "╮"
#define A_BLOCK_GP "˃"
#define S_BLOCK_GP " "

#define Q_BLOCK_Gl "╰"
#define W_BLOCK_GL "─"
#define E_BLOCK_GL "╭ "
#define A_BLOCK_GL "˃"
#define S_BLOCK_GL " "

#define A_BL_LOG "█"
#define Q_BL_LOG " "


#define WALL_TEXTURE_ {\
{Q_BLOCK1, W_BLOCK1, E_BLOCK1},\
        {A_BLOCK1, S_BLOCK1, A_BLOCK1},\
        {Z_BLOCK1, W_BLOCK1, C_BLOCK1},\
}

#define BODY_SIDE {\
{W_BLOCK_B_S, W_BLOCK_B_S, W_BLOCK_B_S},\
        {S_BLOCK_B_S, S_BLOCK_B_S, S_BLOCK_B_S},\
        {W_BLOCK_B_S, W_BLOCK_B_S, W_BLOCK_B_S},\
}

#define BODY_FORWARD {\
{A_BLOCK_B_F, S_BLOCK_B_F, A_BLOCK_B_F},\
        {A_BLOCK_B_F, S_BLOCK_B_F, A_BLOCK_B_F},\
        {A_BLOCK_B_F, S_BLOCK_B_F, A_BLOCK_B_F},\
}

#define HVOST_DWN {\
{Q_BLOCK_DWN, W_BLOCK_DWN, E_BLOCK_DWN},\
        {A_BLOCK_DWN, S_BLOCK_DWN, A_BLOCK_DWN},\
        {A_BLOCK_DWN, S_BLOCK_DWN, A_BLOCK_DWN},\
}

#define HVOST_LEFT {\
{W_BLOCK_LF, W_BLOCK_LF, Q_BLOCK_LF},\
        {S_BLOCK_LF, S_BLOCK_LF, A_BLOCK_LF},\
        {W_BLOCK_LF, W_BLOCK_LF, E_BLOCK_LF},\
}

#define HVOST_RIGHT {\
{Q_BLOCK_RT, W_BLOCK_RT, W_BLOCK_RT},\
        {A_BLOCK_RT, S_BLOCK_RT, S_BLOCK_RT},\
        {E_BLOCK_RT, W_BLOCK_RT, W_BLOCK_RT},\
}


#define HVOST_UP {\
        {A_BLOCK_UP, S_BLOCK_UP, A_BLOCK_UP},\
        {A_BLOCK_UP, S_BLOCK_UP, A_BLOCK_UP},\
        {Q_BLOCK_UP, W_BLOCK_UP, E_BLOCK_UP},\
}

#define COIN {\
        {Q_BLOCK_COIN, W_BLOCK_COIN, E_BLOCK_COIN},\
        {A_BLOCK_COIN, S_BLOCK_COIN, A_BLOCK_COIN},\
        {Z_BLOCK_COIN, W_BLOCK_COIN, C_BLOCK_COIN},\
}

#define GOLOVA_LEVO {\
        {E_BLOCK_GL, W_BLOCK_GL, W_BLOCK_GL},\
        {A_BLOCK_GL, S_BLOCK_GL, S_BLOCK_GL},\
        {Q_BLOCK_Gl, W_BLOCK_GL, W_BLOCK_GL},\
}

#define GOLOVF_PRAVO {\
        {W_BLOCK_GP, W_BLOCK_GP, E_BLOCK_GP},\
        {S_BLOCK_GP, S_BLOCK_GP, A_BLOCK_GP},\
        {W_BLOCK_GP, W_BLOCK_GP, Q_BLOCK_GP},\
}

#define GOLOVA_VNIZ {\
        {A_BLOCK_VN, Q_BLOCK_VN, A_BLOCK_VN},\
        {A_BLOCK_VN, Q_BLOCK_VN, A_BLOCK_VN},\
        {S_BLOCK_VN, W_BLOCK_VN, E_BLOCK_VN},\
}

#define GOLOVA_UP {\
        {Q_BLOCK_GOLOVA, W_BLOCK_GOLOVA, E_BLOCK_GOLOVA},\
        {A_BLOCK_GOLOVA, S_BLOCK_GOLOVA, A_BLOCK_GOLOVA},\
        {A_BLOCK_GOLOVA, S_BLOCK_GOLOVA, A_BLOCK_GOLOVA},\
}

#define L_21_ID_11 {\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, A_BL_LOG, A_BL_LOG},\
}

#define L_21_ID_21 {\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {A_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_31 {\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {A_BL_LOG Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_12 {\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, A_BL_LOG},\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_22 {\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
        {A_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_32 {\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_13 {\
        {Q_BL_LOG, Q_BL_LOG, A_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_23 {\
        {A_BL_LOG, A_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_ID_33 {\
        {Q_BL_LOG, A_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
        {Q_BL_LOG, Q_BL_LOG, Q_BL_LOG},\
}

#define L_21_FULL {\
        {L_21_ID_11, L_21_ID_21, L_21_ID_31},\
        {L_21_ID_12, L_21_ID_22, L_21_ID_32},\
        {L_21_ID_13, L_21_ID_23, L_21_ID_33}\
}


#endif  // SRC_TEXTURES_WALL_H_
