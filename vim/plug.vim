"Vundle{
    set nocompatible              " be iMproved, required
    filetype off                  " required

    " set the runtime path to include Vundle and initialize
    set rtp+=$SELFHOME/bundle/Vundle.vim
    " alternatively, pass a path where Vundle should install plugins
    call vundle#begin('~/workshell/vim/bundle')
"    call vundle#begin()

    "1. 在Github vim-scripts 用户下的repos,只需要写出repos名称
    "2. 在Github其他用户下的repos, 需要写出”用户名/repos名”
    "3. 不在Github上的插件，需要写出git全路径


    " let Vundle manage Vundle, required
    Plugin 'VundleVim/Vundle.vim'

    " The following are examples of different formats supported.
    " Keep Plugin commands between vundle#begin/end.
    " plugin on GitHub repo
    Plugin 'tpope/vim-fugitive'
    " plugin from http://vim-scripts.org/vim/scripts.html
"    Plugin 'L9'
    " Git plugin not hosted on GitHub
    Plugin 'git://git.wincent.com/command-t.git'
    " git repos on your local machine (i.e. when working on your own plugin)
    "Plugin 'file:///home/gmarik/path/to/plugin'
    " The sparkup vim script is in a subdirectory of this repo called vim.
    " Pass the path to set the runtimepath properly.
    Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
    " Install L9 and avoid a Naming conflict if you've already installed a
    " different version somewhere else.
    Plugin 'ascenator/L9', {'name': 'newL9'}

    Bundle 'scrooloose/syntastic'

    Plugin 'scrooloose/nerdtree'
    Plugin 'Xuyuanp/nerdtree-git-plugin'

"    Bundle 'Valloric/YouCompleteMe'

"    Plugin 'shawncplus/phpcomplete.vim'
    " All of your Plugins must be added before the following line
    call vundle#end()            " required
    filetype plugin indent on    " required
    " To ignore plugin indent changes, instead use:
    "filetype plugin on
    "
    " Brief help
    " :PluginList       - lists configured plugins
    " :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
    " :PluginSearch foo - searches for foo; append `!` to refresh local cache
    " :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
    "
    " see :h vundle for more details or wiki for FAQ
    " Put your non-Plugin stuff after this line
"}






"phpcheck{
    " phpcheck 插件
    let g:PHP_SYNTAX_CHECK_BIN = '/usr/bin/php'
"}

"ctags{
    "设置ctags程序路径
    let Tlist_Ctags_Cmd = '/usr/local/bin/ctags'

    "设置taglist打开关闭的快捷键F8
    noremap <F8> :TlistToggle<CR>

    "更新ctags标签文件快捷键设置
    noremap <F6> :!ctags -R --language-force=php<CR>

    "启动vim后自动打开taglist窗口
    let Tlist_Auto_Open = 0

    "不同时显示多个文件的tag，仅显示一个
    let Tlist_Show_One_File = 1

    "taglist为最后一个窗口时，退出vim
    let Tlist_Exit_OnlyWindow = 1

    "taglist窗口显示在右侧，缺省为左侧
    let Tlist_Use_Right_Window =1

    "设置taglist窗口大小
    "let Tlist_WinHeight = 100
    let Tlist_WinWidth = 40

    " 如果想在选择了tag后自动关闭taglist窗口
    let Tlist_Close_On_Select = 1

    " 打开taglist光标保留在taglist窗口
    let Tlist_GainFocus_On_ToggleOpen = 1

    " ctags 插件
    set tags=tags;    " 指定生成tags文件地址,此处指当前工作目录
"}

"nerd_tree{
    " 目录窗口开关
    map <C-n> :NERDTreeToggle<CR>
    " 如果关闭仅有的一个窗口，vim将退出
    autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
    let g:NERDTreeDirArrowExpandable = '▸'
    let g:NERDTreeDirArrowCollapsible = '▾'
"}


"powerline{
    set fillchars+=stl:\ ,stlnc:\
    set term=xterm-256color
    set termencoding=utf-8
    set encoding=utf-8
    set nocompatible 
    set t_Co=256 

    let g:Powerline_symbols= 'unicode'
"    let g:Powerline_symbols = 'fancy'
    let g:minBufExplForceSyntaxEnable = 1 
"    let g:Powerline_theme = 'default'
    python from powerline.vim import setup as powerline_setup 
    python powerline_setup() 
    python del powerline_setup 

    set laststatus=2 
    set guifont=Source\ Code\ Pro\ for\ Powerline:h12 
    "set guifont=Meslo\ LG\ S\ for\ Powerline
    set noshowmode

"    let g:Powerline_stl_path_style = 'full'
"}

" syntastic{
    let g:syntastic_check_on_open = 1
    let g:syntastic_cpp_include_dirs = ['/usr/include/']
    let g:syntastic_cpp_remove_include_errors = 1
    let g:syntastic_cpp_check_header = 1
    let g:syntastic_cpp_compiler = 'clang++'
    let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libstdc++'
    "set c options
    let g:syntastic_c_include_dirs = ["includes", "headers"]
    let g:syntastic_c_oclint_post_args = ""
    let g:syntastic_c_sparse_post_args="-gcc-base-dir " .
        \ system("gcc -v 2>&1 | sed -n '/^Reading specs/ { s#.* /#/#; s#/[^/]*$##; p; }'")
    "set error or warning signs
    let g:syntastic_error_symbol = '✗'
    let g:syntastic_warning_symbol = '⚠'
    ""whether to show balloons
    let g:syntastic_enable_balloons = 1
" }

"YouCompleteMe {
"    let g:ycm_autoclose_preview_window_after_completion=1
"    map <leader>g  :YcmCompleter GoToDefinitionElseDeclaration<CR>
"}
" phpcomplete {
    filetype plugin on
    autocmd FileType php set omnifunc=phpcomplete
"}

