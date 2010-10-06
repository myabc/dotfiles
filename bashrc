export CLICOLOR=1
# use yellow for directories
# export LSCOLORS=dxfxcxdxbxegedabagacad
# use cyan for directories
export LSCOLORS=gxfxcxdxbxegedabagacad

# rvm-install added line:
[[ -s "$HOME/.rvm/scripts/rvm" ]] && . "$HOME/.rvm/scripts/rvm"

source ~/.git-completion.sh
PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$ '
# PS1="\$(~/.rvm/bin/rvm-prompt)$PS1"

# -- start rip config -- #
RIPDIR=/Users/alexbcoles/.rip
RUBYLIB="$RUBYLIB:$RIPDIR/active/lib"
PATH="$PATH:$RIPDIR/active/bin"
export RIPDIR RUBYLIB PATH
# -- end rip config -- #
