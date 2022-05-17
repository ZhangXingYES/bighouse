;; Auto-generated. Do not edit!


(when (boundp 'demo_topic::Person)
  (if (not (find-package "DEMO_TOPIC"))
    (make-package "DEMO_TOPIC"))
  (shadow 'Person (find-package "DEMO_TOPIC")))
(unless (find-package "DEMO_TOPIC::PERSON")
  (make-package "DEMO_TOPIC::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(defclass demo_topic::Person
  :super ros::object
  :slots (_name _id _banji ))

(defmethod demo_topic::Person
  (:init
   (&key
    ((:name __name) "")
    ((:id __id) 0)
    ((:banji __banji) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _id (round __id))
   (setq _banji (round __banji))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:banji
   (&optional __banji)
   (if __banji (setq _banji __banji)) _banji)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint32 _id
    4
    ;; uint8 _banji
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint32 _id
       (write-long _id s)
     ;; uint8 _banji
       (write-byte _banji s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _banji
     (setq _banji (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get demo_topic::Person :md5sum-) "44a45cefcb74f483840e2bf073c0d46f")
(setf (get demo_topic::Person :datatype-) "demo_topic/Person")
(setf (get demo_topic::Person :definition-)
      "string name
uint32 id
uint8 banji

")



(provide :demo_topic/Person "44a45cefcb74f483840e2bf073c0d46f")


