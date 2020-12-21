#--------------------------------------------------------------
# User specific aliases and functions
#--------------------------------------------------------------
alias vi='vim'
alias view='vim -R'
if [ "x$OS" == "xMac" ];then
	alias ls='ls -G'
	alias readlink='greadlink'
	alias showip="ifconfig | fgrep 'inet ' -B4"
else
	alias ls='ls --color=auto'
	alias lsg='ls --group-directories-first'
fi
alias ll='ls -l'
alias la='ls -A'
alias l.='ls -d .*'
alias lsd='ls -d */'
alias l='ls -CF'
alias mv='mv -iv'
alias cp='cp -iv'
alias rm='rm-trash'
alias del='\rm -iv'
#alias grep='grep --color -i -n'
alias grep='grep --color'
#alias fgrep='fgrep --color -i -n'
alias fgrep='fgrep --color'
# alias tee='tee -a'
alias diff='diff -b -B'
alias diffdir='diff -ruNa --brief'
alias watch='watch -d -n 1'
if [ "x$OS" == "xLinux" ];then
	alias top='top -s'
fi
# alias tcpdump='tcpdump -elXnnvvv'
# alias rsync='rsync -avzP'
# alias apt='apt-get -o Acquire::http::proxy="http://127.0.0.1:8087/"'
# alias wget-dir='wget -c -r -np -nd'
# alias java-proxy='java -jar -Xms1024M -Xmx1024M -Dhttp.proxyHost=127.0.0.1 -Dhttp.proxyPort=8087'

#--------------------------------------------------------------
# BASH basic config
#--------------------------------------------------------------

# Set dir_colors
if [ -f ~/.dir_colors ];
then
	eval $(dircolors ~/.dir_colors)
else
	export LS_COLORS='di=01;34'
fi

# specified environment variable
# export LANG=en_US.UTF-8
export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
export HISTTIMEFORMAT='%F %T '
export HISTCONTROL=erasedups
export TIMEFORMAT=$'\nRealTime=%3lR  UserTime=%3lU  SysTime=%3lS  CPU=%P%%'

# DIY bash prompt
# export PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$'	# default of PS1
# $LINES: 当前终端行数	$COLUMNS: 当前终端列数
# ip=`ifconfig | grep -A1 "eth0\|wlan0" | fgrep inet | cut -d ":" -f 2 | cut -d " " -f 1 | xargs | sed "s/ / \& /g"`
# ip=${ip:=0.0.0.0}
host=$(hostname)
if [ x$LANG = 'xen_US.UTF-8' -o x$LANG = 'xen_US.utf-8' ]; then
	export PS1='`ret=$?; if [ $ret -ne 0 ];then echo "\[\e[31m\]error code: $ret\n\[\e[0m\]"; fi`\[\e[36m\]╔════\[\e[37m\]($host)\[\e[36m\]══`for((i=0;i<$COLUMNS-39-${#host};++i));do echo -n ═;done` \[\e[1m\e[33m\]$(date +"%a %F %T")\[\e[0m\e[36m\] ════╗\n\[\e[36m\]╠\[\e[0m\]\W\$ '
	export PS2='\[\e[36m\]╠\[\e[0m\]\W\$ '
else
	export PS1='`ret=$?; if [ $ret -ne 0 ];then echo "\[\e[31m\]error code: $ret\n\[\e[0m\]"; fi`\[\e[36m\]|----\[\e[37m\]($host)\[\e[36m\]--`for((i=0;i<$COLUMNS-39-${#host};++i));do echo -n -;done` \[\e[1m\e[33m\]$(date +"%a %F %T")\[\e[0m\e[36m\] ----|\n\[\e[36m\]|\[\e[0m\]\W\$ '
	export PS2='\[\e[36m\]|\[\e[0m\]\W\$ '
fi

# 在shell脚本中使用-x参数时，打印行号和函数名
export PS4='+[$LINENO:${FUNCNAME[0]}] '

# set umask
umask 022

#--------------------------------------------------------------
# Tmux alias
#--------------------------------------------------------------
alias tm='tmux'
alias tmls='tmux ls'
alias tmnew='tmux new -s'
alias tmn=tmnew
alias tmattach='tmux attach -t'
alias tma=tmattach
alias tmswitch='tmux switch -t'
alias tmrename='tmux rename-session -t'
alias tmk='tmux kill-session -t'
alias tmsplit='tmux split-window'
alias ts=tmsplit
alias tmvslpit='tmux split-window -h'
alias tsv=tmvslpit

#--------------------------------------------------------------
# GCC aliases and functions
#--------------------------------------------------------------

alias as='as -gstabs'
# alias cc='gcc -ansi -pedantic -Wall -Wextra -Wc++-compat -Wconversion -g3'
alias cc='gcc -Wall -Wextra -g3'
# alias ccp='g++ -ansi -pedantic -Wall -Wextra -Wc++0x-compat -Wconversion -g3'
alias ccp='g++ -Wall -Wextra -g3'
alias ar='ar crv'
if [ "x$OS" == "xLinux" ];then
	alias ctags='\ctags'
	alias ctags-c='ctags --c-kinds=+p --fields=+S --links=yes --languages=c --langmap=c:+.h --file-scope=yes -I __THROW'
	alias ctags-c++='ctags --c++-kinds=+p --fields=+iaS --extra=+q+f --tag-relative=yes --languages=c++ --exclude=.svn'
fi

# alias gdb='gdb | tee ~/temp/gdb.out'
################################
# the other way to make gdb log:
# set set logging on
# set set logging off
# set set logging file FILE
################################

#--------------------------------------------------------------
# Git config
#--------------------------------------------------------------
# git打开调试命令
# export GIT_TRACE_PACKET=1
# export GIT_TRACE=1
# export GIT_CURL_VERBOSE=1

