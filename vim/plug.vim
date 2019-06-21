"Vundle{
    set nocompatible              " be iMproved, required
    filetype off                  " required

    " set the runtime path to include Vundle and initialize
    set rtp+=$SELFHOME/bundle/Vundle.vim
    " alternatively, pass a path where Vundle should install plugins
    call vundle#begin('$SELFHOME/bundle')
"    call vundle#begin()

    "1. 在Github vim-scripts 用户下的repos,只需要写出repos名称
    "2. 在Github其他用户下的repos, 需要写出”用户名/repos名”
    "3. 不在Github上的插件，需要写出git全路径


    " The following are examples of different formats supported.
    " Keep Plugin commands between vundle#begin/end.
    " plugin on GitHub repo
"    Plugin 'tpope/vim-fugitive'
    " plugin from http://vim-scripts.org/vim/scripts.html
"    Plugin 'L9'
    " Git plugin not hosted on GitHub
"    Plugin 'git://git.wincent.com/command-t.git'
    " git repos on your local machine (i.e. when working on your own plugin)
    "Plugin 'file:///home/gmarik/path/to/plugin'
    " The sparkup vim script is in a subdirectory of this repo called vim.
    " Pass the path to set the runtimepath properly.
"    Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
    " Install L9 and avoid a Naming conflict if you've already installed a
    " different version somewhere else.
"    Plugin 'ascenator/L9', {'name': 'newL9'}
"    Plugin 'nerdtree'

"   编辑器功能扩展
    " let Vundle manage Vundle, required                                                                                                         
"    Bundle 'Lokaltog/vim-powerline' 
    Plugin 'VundleVim/Vundle.vim'
    Bundle 'scrooloose/syntastic'
    Bundle 'taglist.vim'
    Plugin 'scrooloose/nerdtree'
    Plugin 'Xuyuanp/nerdtree-git-plugin'
    Bundle 'Valloric/YouCompleteMe'

"   代码支持
    Plugin 'SirVer/ultisnips'
    Bundle "honza/vim-snippets"

"   语言支持
    Plugin 'fatih/vim-go'
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







"ctags{
    "设置ctags程序路径
    let Tlist_Ctags_Cmd = '/usr/local/bin/ctags'

    "设置taglist打开关闭的快捷键F8
    noremap <F8> :TlistToggle<CR>

    "更新ctags标签文件快捷键设置
    noremap <F6> :!ctags --languages=php -R <CR>

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
    let Tlist_Close_On_Select = 0

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
"    let NERDTreeIgnore=['\.pyc$', '\~$'] "ignore files in NERDTree
"}


"powerline{
"    set fillchars+=stl:\ ,stlnc:\
"    set term=xterm-256color
"    set termencoding=utf-8
"    set encoding=utf-8
"    set nocompatible 
"    set t_Co=256 
"
"    let g:Powerline_symbols= 'unicode'
"    let g:minBufExplForceSyntaxEnable = 1 
"
"    set laststatus=2 
"    set guifont=Source\ Code\ Pro\ for\ Powerline:h12 
"}

" syntastic{
"    let g:syntastic_check_on_open = 1
"    let g:syntastic_cpp_include_dirs = ['/usr/include/']
"    let g:syntastic_cpp_remove_include_errors = 1
"    let g:syntastic_cpp_check_header = 1
"    let g:syntastic_cpp_compiler = 'clang++'
"    let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libstdc++'
"    "set c options
"    let g:syntastic_c_include_dirs = ["includes", "headers"]
"    let g:syntastic_c_oclint_post_args = ""
"    let g:syntastic_c_sparse_post_args="-gcc-base-dir " .
"        \ system("gcc -v 2>&1 | sed -n '/^Reading specs/ { s#.* /#/#; s#/[^/]*$##; p; }'")
"    "set error or warning signs
"    let g:syntastic_error_symbol = '✗'
"    let g:syntastic_warning_symbol = '⚠'
"    " whether to show balloons
"    let g:syntastic_enable_balloons = 1
" }

" phpcomplete {
    " https://github.com/shawncplus/phpcomplete.vim
"}


"phpcheck{
    " http://www.vim.org/scripts/script.php?script_id=4984
"    let g:PHP_SYNTAX_CHECK_BIN = '/usr/bin/php'
"    let g:PHP_SYNTAX_CHECK_BIN = $php_path
"}


" SirVer/ultisnips {
    " Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
"    let g:UltiSnipsExpandTrigger="<tab>"
    let g:UltiSnipsExpandTrigger="<C-l>"
    let g:UltiSnipsJumpForwardTrigger="<C-l>"
    let g:UltiSnipsJumpBackwardTrigger="<C-z>"
" }


"YouCompleteMe {
    " https://github.com/Valloric/YouCompleteMe
    let g:ycm_server_python_interpreter=$python3_path
<<<<<<< HEAD
    let g:ycm_global_ycm_extra_conf='$SELFHOME/bundle/YouCompleteMe/.ycm_extra_conf.py'
=======
    let g:ycm_global_ycm_extra_conf='/usr/local/workshell/vim/bundle/YouCompleteMe/.ycm_extra_conf.py'
>>>>>>> 4837ec9083e3d35b99cd0bb4a1531277e6d23712

    " 开启基于tag的补全，可以在这之后添加需要的标签路径
    let g:ycm_collect_identifiers_from_tags_files=1

    "在注释输入中也能补全
    let g:ycm_complete_in_comments = 1
    "在字符串输入中也能补全
    let g:ycm_complete_in_strings = 1
    "注释和字符串中的文字也会被收入补全
    let g:ycm_collect_identifiers_from_comments_and_strings = 0

    let g:ycm_log_level = 'info'
    let g:ycm_show_diagnostics_ui = 1
    highlight YcmErrorLine guibg=#3f0000
    let g:ycm_error_symbol = '>>'
    let g:ycm_warning_symbol = '>*'

    let g:ycm_collect_identifiers_from_tags_files=1	" 开启 YCM 基于标签引擎
    let g:ycm_min_num_of_chars_for_completion=2	" 从第2个键入字符就开始罗列匹配项
    let g:ycm_cache_omnifunc=1	                " 禁止缓存匹配项,每次都重新生成匹配项
    let g:ycm_seed_identifiers_with_syntax=1	" 语法关键字补全
    let g:EclimCompletionMethod = 'omnifunc'


    let g:ycm_autoclose_preview_window_after_completion=1
    map <leader>g  :YcmCompleter GoToDefinitionElseDeclaration<CR>

"    let g:ycm_semantic_triggers =  {
"      \   'c' : ['->', '.'],
"      \   'objc' : ['->', '.', 're!\[[_a-zA-Z]+\w*\s', 're!^\s*[^\W\d]\w*\s',
"      \             're!\[.*\]\s'],
"      \   'ocaml' : ['.', '#'],
"      \   'cpp,objcpp' : ['->', '.', '::'],
"      \   'perl' : ['->'],
"      \   'php' : ['->', '::'],
"      \   'cs,java,javascript,typescript,d,python,perl6,scala,vb,elixir,go' : ['.'],
"      \   'ruby' : ['.', '::'],
"      \   'lua' : ['.', ':'],
"      \   'erlang' : [':'],
"      \ }


    " 跳转到定义处
    nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR> 
    inoremap <leader><leader> <C-x><C-o>
"    nmap <F4> :YcmDiags<CR>
    nmap <F4> :YcmShowDetailedDiagnostic<CR>


"}



" python with virtualenv support
"py << EOF
"import os.path
"import sys
"import vim
"if 'VIRTUA_ENV' in os.environ:
"   project_base_dir = os.environ['VIRTUAL_ENV']
"   sys.path.insert(0, project_base_dir)
"   activate_this = os.path.join(project_base_dir,'bin/activate_this.py')
"   execfile(activate_this, dict(__file__=activate_this))
"EOF


" 根据文件类型处理 
filetype on
filetype plugin on 
autocmd FileType python set omnifunc=pythoncomplete#Complete
autocmd FileType python3 set omnifunc=python3complete#Complete
autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
autocmd FileType html set omnifunc=htmlcomplete#CompleteTags
autocmd FileType css set omnifunc=csscomplete#CompleteCSS
autocmd FileType xml set omnifunc=xmlcomplete#CompleteTags
autocmd FileType php set omnifunc=phpcomplete#CompletePHP
autocmd FileType c set omnifunc=ccomplete#Complete
