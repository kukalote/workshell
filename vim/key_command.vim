""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""快捷键-命令""""""""""""""""""""""""""""""""""""""""""
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 自动加载vimrc, 无需重启gvim
"autocmd! bufwritepost _vimrc source %
"autocmd BufWritePost $MYVIMRC source $MYVIMRC
" 设置前缀命令
let mapleader = ","
" 编辑配置文件
map <silent> <leader>ee :e $SELFHOME/sets.vim<CR>:noh<cr>
" 加载配置文件 
map <silent> <leader>em :source $MYVIMRC<CR>:noh<cr>

" 窗口跳转
nmap <C-k> <C-W>k
nmap <C-h> <C-W>h
nmap <C-j> <C-W>j
nmap <C-l> <C-W>l

" 插入模式自动转换
"imap ex example



" lhs comments
map <leader># :s/^/#/<CR>:noh<CR>
map <leader>/ :s/^/\/\//<CR>:noh<CR>
map <leader>> :s/^/> /<CR>:noh<CR>
map <leader>" :s/^/\"/<CR>:noh<CR>
map <leader>% :s/^/%/<CR>:noh<CR>
map <leader>! :s/^/!/<CR>:noh<CR>
map <leader>; :s/^/;/<CR>:noh<CR>
map <leader>- :s/^/-- /<CR>:noh<CR>
map <leader>' :s/^["#;\/!-]*//<CR>:noh<CR>
"map ,c :s/^\/\/\\|^--\\|^> \\|^[#"%!;]//<CR>:noh<CR>

" wrapping comments
map <leader>* :'<,'>s/^\(.*\)$/\/\* \1 \*\//<CR>:noh<CR>
"map <leader>( :s/^\(.*\)$/\(\* \1 \*\)/<CR>:noh<CR>
map <leader>< :s/^\(.*\)$/<!-- \1 -->/<CR>:noh<CR>
"map ,d :s/^\([/(]\*\\|<!--\) \(.*\) \(\*[/)]\\|-->\)$/\2/<CR>:noh<CR>

"
" 添加php调试输出
nmap <silent> <leader>var ovar_dump('a');exit;<Esc>:w<CR>4blvh%h

" 重定义:E命令
"cabbrev E Explore
"command! E Explore
command E Explore



