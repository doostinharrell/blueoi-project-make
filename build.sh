#!/bin/bash

MAKEFILE="project.make"
DRUSH_OPTS='--concurrency=16'
WORKING_PATH=`cd "$CALLPATH"; pwd -P`
PROJECT_PATH="${WORKING_PATH%\/*}"
TMP_PATH="$PROJECT_PATH/tmp"
BUILD_PATH="$PROJECT_PATH/www"

echo '=============================================='
echo '               Syncing Files                  '
echo '=============================================='

set -e

echo '=============================================='
echo '         Building Drupal Installation         '
echo '=============================================='

if [ $BUILD_PATH ]; then
  rm -Rf $BUILD_PATH
fi

drush make $DRUSH_OPTS "$WORKING_PATH/$MAKEFILE" $TMP_PATH
rsync -vrq --delete --exclude-from=$WORKING_PATH/rsync.exclude $TMP_PATH/ $BUILD_PATH/

if [ ! -L "$BUILD_PATH/sites/default/libraries" ]; then
  ln -s ../../../project/libraries ../www/sites/default/libraries
fi

if [ ! -L "$BUILD_PATH/sites/default/modules" ]; then
  ln -s ../../../project/modules ../www/sites/default/modules
fi

if [ ! -L "$BUILD_PATH/sites/default/themes" ]; then
  ln -s ../../../project/themes ../www/sites/default/themes
fi

rm -Rf $TMP_PATH

set +e

echo '=============================================='
echo '                   Clean Up                   '
echo '=============================================='

cd $BUILD_PATH
drush rr
drush cc all

echo '=============================================='
echo '            Project Build Complete            '
echo '=============================================='
