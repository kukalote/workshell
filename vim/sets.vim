"重载当前配置文件
" :source $MYVIMRC

" 允许鼠标在终端复制 
if has("mouse")
    set mouse-=a
endif

" 无BOM 头
set nobomb

" 文件编码
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
language messages zh_CN.utf-8

" 显示行号
set nu
" 显示相对行号
set rnu

" 根据上一行决定新行的缩进
set autoindent

" 覆盖文件时保留备份文件
" set backupcopy=auto

" 不生成备份
set nobackup
set nowritebackup
set noswapfile
set noundofile
set bufhidden=hide

" 自动切换工作目录 
":cd %:h

" 自动切换工作目录 
"set autochdir

" 自动加载修改
set autoread

" 高亮指定列
" set colorcolumn

" 高亮光标所在屏幕行
set cursorline
" hi CursorLine cterm=NONE ctermbg=black ctermfg=green guibg=green guifg=green

" 高亮最近的匹配搜索模式
set hlsearch
" 在搜索的时候忽略大小写
set ignorecase

" 输入搜索模式时同时高亮部分的匹配
set incsearch


" 开始编辑文件时进入插入模式
" set insertmode

" 显示屏幕的行数
"set lines

" % 能匹配的字符对
set matchpairs=(:),{:},[:],<:>

" 标尺，在状态行里显示光标的行号和列号
set ruler

" 在状态行里显示 (部分) 命令
set showcmd

" 用于提示回绕行开始的字符串
" set showbreak

" 自动补全标签时显示完整的标签匹配模式
set showfulltag

" 插入括号时短暂跳转到匹配的括号
set showmatch

" 在状态行上显示当前模式的消息
set showmode

set laststatus=2

" 是否显示标签页行
set showtabline=1

" 打开关键字色
syntax on
syntax enable

set history=50          " keep 50 lines of command line history

"模式中有大写字母时不忽略大小写
set smartcase
"C 程序智能自动缩进
set smartindent
"插入 <Tab> 时使用 'shiftwidth'
set smarttab

"<Tab> 在文件里使用的空格数
set tabstop=4
" (自动) 缩进使用的步进单位，以空白数目计
set shiftwidth=4
"编辑时 <Tab> 使用的空格数
set softtabstop=4
"键入 <Tab> 时使用空格
set expandtab

"打开C/C++风格的自动缩进。
set cindent
"设定C/C++风格自动缩进的选项。
set cinoptions=:0g0t0(sus


"命令移动光标到行的第一个非空白
set startofline
" 搜索在文件尾折回文件头
set wrapscan
"不在单词中间断行，尽量在单词间空白处断开
set lbr
"打开断行模块对亚洲语言支持。m表示允许在两个汉字之间断行，即使汉字之间没有出现空格
"B表示将两行合并为一行的时候，汉字与汉字之间不要补空格。该命令支持的更多选项请看用户手册
set fo+=mB

" 长行回绕并在下一行继续
set nowrap

"设置主题
colorscheme torte
"colorscheme xun


" 显示 <Tab> 和 <EOL>
"set list
set listchars=eol:$,tab:--,trail:*,extends:<,precedes:@,nbsp:%


" 高亮字符，让其不受100列限制
" highlight OverLength ctermbg=red ctermfg=white guibg=red guifg=white
" match OverLength '\1v.*'
" 状态行颜色
highlight StatusLine guifg=SlateBlue guibg=Yellow
highlight StatusLineNC guifg=Gray guibg=White
hi CursorLine   term=underline cterm=underline ctermfg=NONE ctermbg=238 gui=underline guibg=Darkred


" 通过使用: commands命令，告诉我们文件的哪一行被改变过
"set report=0
" 不让vim发出讨厌的滴滴声
set noerrorbells
" 在被分割的窗口间显示空白，便于阅读
"set fillchars=vert:\ ,stl:\ ,stlnc:\
set t_RV=

" autocommand
"au BufNewFile,BufRead *.js, *.html, *.css
"    \ set tabstop=2
"    \ set softtabstop=2
"    \ set shiftwidth=2

"au BufNewFile,BufRead  *.py
"    \ set textwidth=100
au BufNewFile,BufRead *.py 
\ set tabstop=4 | 
\ set softtabstop=4| 
\ set shiftwidth=4| 
\ set textwidth=79| 
\ set expandtab| 
\ set autoindent| 
\ set fileformat=unix



" 标示不必要的空白字符
hi BadWhitespace guifg=gray guibg=darkred ctermfg=gray ctermbg=red
au BufRead,BufNewFile *.py,*.pyw,*.c,*.h match BadWhitespace /\s\+$/
