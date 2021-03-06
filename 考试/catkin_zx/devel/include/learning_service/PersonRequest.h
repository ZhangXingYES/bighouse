// Generated by gencpp from file learning_service/PersonRequest.msg
// DO NOT EDIT!


#ifndef LEARNING_SERVICE_MESSAGE_PERSONREQUEST_H
#define LEARNING_SERVICE_MESSAGE_PERSONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learning_service
{
template <class ContainerAllocator>
struct PersonRequest_
{
  typedef PersonRequest_<ContainerAllocator> Type;

  PersonRequest_()
    : name()
    , banji()
    , id(0)  {
    }
  PersonRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , banji(_alloc)
    , id(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _banji_type;
  _banji_type banji;

   typedef uint32_t _id_type;
  _id_type id;





  typedef boost::shared_ptr< ::learning_service::PersonRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_service::PersonRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PersonRequest_

typedef ::learning_service::PersonRequest_<std::allocator<void> > PersonRequest;

typedef boost::shared_ptr< ::learning_service::PersonRequest > PersonRequestPtr;
typedef boost::shared_ptr< ::learning_service::PersonRequest const> PersonRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_service::PersonRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_service::PersonRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learning_service::PersonRequest_<ContainerAllocator1> & lhs, const ::learning_service::PersonRequest_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.banji == rhs.banji &&
    lhs.id == rhs.id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learning_service::PersonRequest_<ContainerAllocator1> & lhs, const ::learning_service::PersonRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learning_service

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::learning_service::PersonRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_service::PersonRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_service::PersonRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_service::PersonRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_service::PersonRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_service::PersonRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_service::PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f6b78bdcceae389b0b3ad77e08eb2a20";
  }

  static const char* value(const ::learning_service::PersonRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf6b78bdcceae389bULL;
  static const uint64_t static_value2 = 0x0b3ad77e08eb2a20ULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_service::PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_service/PersonRequest";
  }

  static const char* value(const ::learning_service::PersonRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_service::PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n"
"string banji\n"
"uint32 id\n"
;
  }

  static const char* value(const ::learning_service::PersonRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_service::PersonRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.banji);
      stream.next(m.id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PersonRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_service::PersonRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_service::PersonRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "banji: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.banji);
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_SERVICE_MESSAGE_PERSONREQUEST_H
