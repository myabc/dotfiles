#!/bin/bash
#
# Provides a function that allows you to choose a JDK.  Just set the environment
# variable JDKS_ROOT to the directory containing multiple versions of the JDK
# and the function will prompt you to select one.  JAVA_HOME and PATH will be cleaned
# up and set appropriately.
#
# Adapted from a Gist by headius / nicksieger: http://gist.github.com/143128
# With a few modifications inspired by:
# http://confluence.concord.org/display/CCTR/Build+OpenJDK+Java+1.7.0+on+Mac+OS+X+10.5
#
# sudo mkdir -p /System/Library/Frameworks/JavaVM.framework/Versions/1.6.0-openjdk
# sudo ln -s /opt/local/share/java/openjdk6 /System/Library/Frameworks/JavaVM.framework/Versions/1.6.0-openjdk/Home

_macosx()
{
    if [ $(uname -s) = Darwin ]; then
        return 0
    else
        return 1
    fi
}

JDKS_ROOT=
if _macosx; then
    JDKS_ROOT=/System/Library/Frameworks/JavaVM.framework/Versions
fi

pickjdk()
{
    if [ -z "$JDKS_ROOT" ]; then
        return 1
    fi

    declare -a JDKS
    local n=1 jdk total_jdks choice=0 currjdk=$JAVA_HOME explicit_jdk
    for jdk in $JDKS_ROOT/[0-9osdM]*; do
        if [ -d $jdk -a ! -L $jdk ]; then
            JDKNAMES[$n]="$(basename $jdk)"
            if _macosx; then
                jdk=$jdk/Home
            fi
            if [ -z "$1" ]; then
              echo -n " $n) ${JDKNAMES[$n]}"
              if [ $jdk = "$currjdk" ]; then
                  echo " < CURRENT"
              else
                  echo
              fi
            fi
            JDKS[$n]=$jdk
            total_jdks=$n
            n=$[ $n + 1 ]
        fi
    done
    if [ -z "$1" ]; then
      echo " $n) None"
    fi
    JDKS[$n]=None
    total_jdks=$n

    if [ $total_jdks -gt 1 ]; then
        if [ -z "$1" ]; then
          while [ -z "${JDKS[$choice]}" ]; do
              echo -n "Choose one of the above [1-$total_jdks]: "
              read choice
          done
        else
          choice=$1
        fi
    fi

    if [ -z "$currjdk" ]; then
        currjdk=$(dirname $(dirname $(type -path java)))
    fi

    if [ ${JDKS[$choice]} != None ]; then
        export JAVA_HOME=${JDKS[$choice]}
    else
        unset JAVA_HOME
    fi

    explicit_jdk=
    for jdk in ${JDKS[*]}; do
        if [ "$currjdk" = "$jdk" ]; then
            explicit_jdk=$jdk
            break
        fi
    done

    if [ "$explicit_jdk" ]; then
        if [ -z "$JAVA_HOME" ]; then
            PATH=$(echo $PATH | sed "s|$explicit_jdk/bin:*||g")
        else
            PATH=$(echo $PATH | sed "s|$explicit_jdk|$JAVA_HOME|g")
        fi
    elif [ "$JAVA_HOME" ]; then
        PATH="$JAVA_HOME/bin:$PATH"
    fi

    echo "New JDK: ${JDKNAMES[$choice]}"

    hash -r
    unset JDKS
}
