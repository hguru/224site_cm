api = 2
core = "7.x"

; Include Drupal core makefile
includes[] = drupal-org-core.make

; Cm Platform

projects[cm][type] = "profile"
projects[cm][download][type] = "git"
projects[cm][download][url] = "https://github.com/drupalprojects/cm.git"

; To build from a branch or a tag, uncomment as needed

projects[cm][download][branch] = "7.x-1.x"
;projects[cm][download][tag] = "7.x-1.0"

