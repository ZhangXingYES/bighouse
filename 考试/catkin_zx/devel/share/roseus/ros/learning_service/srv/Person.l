;; Auto-generated. Do not edit!


(when (boundp 'learning_service::Person)
  (if (not (find-package "LEARNING_SERVICE"))
    (make-package "LEARNING_SERVICE"))
  (shadow 'Person (find-package "LEARNING_SERVICE")))
(unless (find-package "LEARNING_SERVICE::PERSON")
  (make-package "LEARNING_SERVICE::PERSON"))
(unless (find-package "LEARNING_SERVICE::PERSONREQUEST")
  (make-package "LEARNING_SERVICE::PERSONREQUEST"))
(unless (find-package "LEARNING_SERVICE::PERSONRESPONSE")
  (make-package "LEARNING_SERVICE::PERSONRESPONSE"))

(in-package "ROS")





(defclass learning_service::PersonRequest
  :super ros::object
  :slots (_name _banji _id ))

(defmethod learning_service::PersonRequest
  (:init
   (&key
    ((:name __name) "")
    ((:banji __banji) "")
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _banji (string __banji))
   (setq _id (round __id))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:banji
   (&optional __banji)
   (if __banji (setq _banji __banji)) _banji)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; string _banji
    4 (length _banji)
    ;; uint32 _id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; string _banji
       (write-long (length _banji) s) (princ _banji s)
     ;; uint32 _id
       (write-long _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _banji
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _banji (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass learning_service::PersonResponse
  :super ros::object
  :slots (_result ))

(defmethod learning_service::PersonResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass learning_service::Person
  :super ros::object
  :slots ())

(setf (get learning_service::Person :md5sum-) "0b5a1fdb305a13a3ffd9a94af9843f15")
(setf (get learning_service::Person :datatype-) "learning_service/Person")
(setf (get learning_service::Person :request) learning_service::PersonRequest)
(setf (get learning_service::Person :response) learning_service::PersonResponse)

(defmethod learning_service::PersonRequest
  (:response () (instance learning_service::PersonResponse :init)))

(setf (get learning_service::PersonRequest :md5sum-) "0b5a1fdb305a13a3ffd9a94af9843f15")
(setf (get learning_service::PersonRequest :datatype-) "learning_service/PersonRequest")
(setf (get learning_service::PersonRequest :definition-)
      "string name
string banji
uint32 id
---
string result

")

(setf (get learning_service::PersonResponse :md5sum-) "0b5a1fdb305a13a3ffd9a94af9843f15")
(setf (get learning_service::PersonResponse :datatype-) "learning_service/PersonResponse")
(setf (get learning_service::PersonResponse :definition-)
      "string name
string banji
uint32 id
---
string result

")



(provide :learning_service/Person "0b5a1fdb305a13a3ffd9a94af9843f15")


