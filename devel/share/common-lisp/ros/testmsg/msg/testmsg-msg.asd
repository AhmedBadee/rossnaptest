
(cl:in-package :asdf)

(defsystem "testmsg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "poto" :depends-on ("_package_poto"))
    (:file "_package_poto" :depends-on ("_package"))
  ))