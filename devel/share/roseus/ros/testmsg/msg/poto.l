;; Auto-generated. Do not edit!


(when (boundp 'testmsg::poto)
  (if (not (find-package "TESTMSG"))
    (make-package "TESTMSG"))
  (shadow 'poto (find-package "TESTMSG")))
(unless (find-package "TESTMSG::POTO")
  (make-package "TESTMSG::POTO"))

(in-package "ROS")
;;//! \htmlinclude poto.msg.html


(defclass testmsg::poto
  :super ros::object
  :slots (_name _id ))

(defmethod testmsg::poto
  (:init
   (&key
    ((:name __name) "")
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _id (round __id))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; int8 _id
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; int8 _id
       (write-byte _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _id 127) (setq _id (- _id 256)))
   ;;
   self)
  )

(setf (get testmsg::poto :md5sum-) "f4f347043a64ae4ea786a068b0a9e07c")
(setf (get testmsg::poto :datatype-) "testmsg/poto")
(setf (get testmsg::poto :definition-)
      "string name
int8 id

")



(provide :testmsg/poto "f4f347043a64ae4ea786a068b0a9e07c")


