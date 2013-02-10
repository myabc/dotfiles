export CLICOLOR=1
# use yellow for directories
# export LSCOLORS=dxfxcxdxbxegedabagacad
# use cyan for directories
export LSCOLORS=gxfxcxdxbxegedabagacad

[[ -s "$HOME/.rvm/scripts/rvm" ]] && . "$HOME/.rvm/scripts/rvm"
[[ -r "$HOME/.rvm/scripts/completion" ]] && . "$HOME/.rvm/scripts/completion"
[[ -s "$HOME/.rvm/contrib/ps1_functions" ]] && . "$HOME/.rvm/contrib/ps1_functions"

ps1_set --prompt ∫

#source ~/.git-completion.sh
#PS1='\[\033[0;34m\]{\[\033[0;32m\]\u@\h\[\033[0;37m\]\[\033[0;34m\]} \[\033[0;37m\]\W\[\033[1;31m\]$(__git_ps1 "(%s)")\[\033[1;34m\]>\[\033[0;37m\]$(~/.rvm/bin/rvm-prompt) \[\033[01;34m\]$\[\033[00m\] '


#PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$ '
#PS1="\$(~/.rvm/bin/rvm-prompt)$PS1"
