# ~/.profile: executed by the command interpreter for login shells.

# the default umask is set in /etc/profile; for setting the umask
# for ssh logins, install and configure the libpam-umask package.
#umask 022

# if running bash
if [ -n "$BASH_VERSION" ]; then
  # include .bashrc if it exists
  if [ -f "$HOME/.bashrc" ]; then
    . "$HOME/.bashrc"
  fi
fi

# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/bin" ] ; then
    PATH="$HOME/bin:$PATH"
fi

#export SYSTEM_OSX='Mac OS X'
#export SYSTEM_TIGER='Mac OS X 10.4'
#export SYSTEM_LEOPARD='Mac OS X 10.5'
#export SYSTEM_NIX='Linux'

export SYSTEM_OSX='darwin9.0'
export SYSTEM_LINUX='linux-gnu'

if [[ $OS_TYPE =~ $SYSTEM_OSX ]]; then
  export EDITOR='mate'
                        # causes issues with crontab -e
  export VISUAL='mate -w'
  export SVN_EDITOR='mate -w'
  export GIT_EDITOR='mate -w'
elif [[ $OS_TYPE =~ $SYSTEM_LINUX ]]; then
  export EDITOR='vim'
  export VISUAL='vim'
else
  export EDITOR='vi'
  export VISUAL='vi'
fi


if [[ $OS_TYPE =~ $SYSTEM_OSX ]]; then
  export JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Home/
fi

if [ $SHELL = "/bin/bash" ] && [ -n "$PS1" ]; then
  if [ -f $HOME/git-repos/dotfiles/pickjdk.sh ]; then
    . $HOME/git-repos/dotfiles/pickjdk.sh
  fi
fi

export JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Home/
#export ANT_HOME=/usr/bin/ant
#export M2_HOME=/usr/local/Cellar/maven/3.0
export CATALINA_HOME=/usr/local/Cellar/tomcat/7.0.6/libexec
export GRAILS_HOME=$HOME/Dev/grails
export ROO_HOME=$HOME/Dev/roo
export AWS_IAM_HOME="/usr/local/Cellar/aws-iam-tools/HEAD/jars"
export AWS_CREDENTIAL_FILE=$HOME/.aws-credentials
export MOO_TOOLS_PACKAGER=$HOME/git-repos/mootools/packager
export AWS_RDS_HOME="/usr/local/Cellar/rds-command-line-tools/1.3.003/jars"

export NODE_PATH=/usr/local/lib/node

export DYLD_LIBRARY_PATH="/usr/local/oracle/instantclient_10_2"
export SQLPATH="/usr/local/oracle/instantclient_10_2"
export TNS_ADMIN="/usr/local/oracle/network/admin"
export NLS_LANG="AMERICAN_AMERICA.UTF8"
export PATH=$PATH:$DYLD_LIBRARY_PATH

PATH=$HOME/bin:$AWS_IAM_HOME:$GRAILS_HOME/bin:$MOO_TOOLS_PACKAGER:/usr/local/bin:/opt/local/bin:/opt/local/sbin:$JAVA_HOME/bin:$PATH:$JRUBY_HOME/bin:/usr/local/mysql/bin:/opt/local/lib/postgresql83/bin:/usr/local/php5/bin:$HOME/Dev/depot_tools:/usr/local/elasticbeanstalk-cli/bin
export PATH

if [ -f ~/.profile_private ]; then
  . ~/.profile_private
fi

# For DataObjects / DataMapper TESTING
#export DO_MYSQL_SPEC_URI="mysql://root:$MYSQL_ROOT_PASS@localhost/do_mysql_test?socket=/var/mysql/mysql.sock"
#export DO_MYSQL_SPEC_JDBC_URI="jdbc:mysql://localhost:3306/do_mysql_test?user=root&password=$MYSQL_ROOT_PASS"
#export DO_SQLSERVER_HOST=192.168.2.110
export DO_MYSQL_HOST=127.0.0.1

export DM_DEV_ROOT=$HOME/git-repos/datamapper
export DM_DEV_BUNDLE_ROOT=$HOME/git-repos/datamapper/bundle

if [[ $OS_TYPE =~ $SYSTEM_OSX ]]; then
  alias gvim='mvim'
fi
