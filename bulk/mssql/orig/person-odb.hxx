// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20302UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "person.hxx"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>

#include <odb/details/unused.hxx>

namespace odb
{
  // person
  //
  template <>
  struct class_traits< ::person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::person >
  {
    public:
    typedef ::person object_type;
    typedef ::person* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mssql/version.hxx>
#include <odb/mssql/forward.hxx>
#include <odb/mssql/binding.hxx>
#include <odb/mssql/mssql-types.hxx>

namespace odb
{
  // person
  //
  template <>
  class access::object_traits_impl< ::person, id_mssql >:
    public access::object_traits< ::person >
  {
    public:
    static const bool rowversion = false;

    struct id_image_type
    {
      long long id_value;
      SQLLEN id_size_ind;

      std::size_t version;
    };

    struct image_type
    {
      // id
      //
      long long id_value;
      SQLLEN id_size_ind;

      // num
      //
      int num_value;
      SQLLEN num_size_ind;

      // str
      //
      mutable mssql::long_callback str_callback;
      SQLLEN str_size_ind;

      std::size_t version;

      mssql::change_callback*
      change_callback ()
      {
        return 0;
      }
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static void
    bind (mssql::bind*,
          image_type&,
          mssql::statement_kind);

    static void
    bind (mssql::bind*, id_image_type&);

    static void
    init (image_type&,
          const object_type&,
          mssql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mssql::object_statements<object_type> statements_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::person, id_common >:
    public access::object_traits_impl< ::person, id_mssql >
  {
  };
}

#include "person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX
