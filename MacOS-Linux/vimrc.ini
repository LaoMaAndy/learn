" vim ~/.vimrc
" 双引号 注释信息
" 显示行号
" 显示标尺，状态栏的行号和列号
:set number
:set ruler
" 显示超长行时自动换行
:set linebreak
" 退格键删除内容
:set backspace=2
" 高亮搜索匹配内容
:set hlsearch
" 总是显示状态栏
:set laststatus=2
" 语法高亮
:syntax on
" 设置主题
:colorscheme desert

"Vim 里有四个主要的使用制表的方法:
" 1. 总是保持 'tabstop' 为 8，设置 'softtabstop' 和 'shiftwidth' 为 4
"    (或 3 或任何你想要的) 然后用 'noexpandtab'。这时，Vim 使用制表和空
"    格的混合，但输入 <Tab> 或 <BS> 键就像每个制表占用 4 (或 3) 个字符一
"    样。
" 2. 设置 'tabstop' 和 'shiftwidth' 为想要的任何值，然后用 'expandtab'。
"    这样，你总是插入空格。改变 'tabstop' 时绝不会影响排版。
" 3. 设置 'tabstop' 和 'shiftwidth' 为想要的任何值，然后用  modeline ，
"    再次编辑时就会重新设置这些值。这只适用于总是使用 Vim 进行文件编辑的
"    情况。
" 4. 永远把 'tabstop' 和 'shiftwidth' 设为相同的值，并用 'noexpandtab'。
"    这样，就可以 (只适用于行首的缩进) 使用任何别人的制表位设置。不过，
"    如果你这么做，最好在第一个非空白字符之后想插入制表时以空格代替。否
"    则，改变 'tabstop' 时，注释等的对齐会不正确。
:set tabstop=8
:set shiftwidth=2
:set softtabstop=2
" 'expandtab' 'et'布尔型  (缺省关闭)
" 插入模式里: 插入 <Tab> 时使用合适数量的空格。如果 'autoindent' 打开，
" '>' 和 '<' 命令使用空格进行缩进。'expandtab' 打开时，要插入实际的制
" 表，可用 CTRL-V<Tab>。另见  :retab  和  ins-expandtab 。
" 'paste' 选项置位时复位本选项，'paste' 选项复位时恢复本选项。
:set expandtab
:set autoindent
:set smartindent
