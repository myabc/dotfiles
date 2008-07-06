export CLICOLOR=1
# use yellow for directories
# export LSCOLORS=dxfxcxdxbxegedabagacad
# use cyan for directories
export LSCOLORS=gxfxcxdxbxegedabagacad

source ~/.git-completion.sh
PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$ '