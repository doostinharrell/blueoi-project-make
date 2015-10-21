#!/bin/bash

MAKEFILE="project.make"
DRUSH_OPTS='--concurrency=16'
WORKING_PATH=`cd "$CALLPATH"; pwd -P`
PROJECT_PATH="${WORKING_PATH%\/*}"
BUILD_PATH="$PROJECT_PATH/www"

echo '=============================================='
echo '               Syncing Files                  '
echo '=============================================='

set -e

if [ $BUILD_PATH ]; then
  if [ $BUILD_PATH/sites/default/files ]; then
    rsync -rq --delete --exclude-from=$WORKING_PATH/rsync.exclude $BUILD_PATH/sites/default/files $WORKING_PATH/files/
  fi

  if [ $BUILD_PATH/sites/all/modules/custom/ ]; then
    rsync -rq --delete --exclude-from=$WORKING_PATH/rsync.exclude $BUILD_PATH/sites/all/modules/custom $WORKING_PATH/modules/
  fi

  if [ $BUILD_PATH/sites/all/themes/custom/ ]; then
    rsync -rq --delete --exclude-from=$WORKING_PATH/rsync.exclude $BUILD_PATH/sites/all/themes/custom $WORKING_PATH/themes/
  fi
fi

echo 'Files Synced'

echo '=============================================='
echo '         Building Drupal Installation         '
echo '=============================================='

if [ $BUILD_PATH ]; then
  rm -Rf $BUILD_PATH
fi

drush make $DRUSH_OPTS "$WORKING_PATH/$MAKEFILE" $BUILD_PATH

# Set up symlinks
if [ ! -h $BUILD_PATH/sites/all/themes/custom ]; then
  rsync -vrq --delete --exclude-from=$WORKING_PATH/rsync.exclude $WORKING_PATH/themes/ $BUILD_PATH/sites/all/themes/custom
fi

if [ ! -h $BUILD_PATH/sites/default/modules/custom ]; then
  rsync -vrq --delete --exclude-from=$WORKING_PATH/rsync.exclude $WORKING_PATH/modules/ $BUILD_PATH/sites/all/modules/custom
fi

if [ ! -h $BUILD_PATH/sites/default/files ]; then
  rsync -vrq --delete --exclude-from=$WORKING_PATH/rsync.exclude $WORKING_PATH/files/ $BUILD_PATH/sites/default/files
fi

if [ ! -h $BUILD_PATH/sites/default/settings.php ]; then
  cp $WORKING_PATH/settings.php $BUILD_PATH/sites/default/settings.php
fi

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