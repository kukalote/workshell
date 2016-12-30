""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""fold 折叠""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""fold 折叠""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

set foldenable           " enable folden
set foldmethod=indent    " manual : Folds are created manually.
                         " indent : Lines with equal indent form a fold.
                         " expr   : ‘foldexpr’ gives the fold level of a line.
                         " marker : Markers are used to specify folds.
                         " syntax : Syntax highlighting items specify folds.
                         " diff   : Fold text that is not changed.

"set foldclose=all
" use space to folden
"nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>
