/* Copyright 2018, UCAR/Unidata See netcdf/COPYRIGHT file for copying
 * and redistribution conditions.*/
/**
 * @file
 * @internal Dispatch code for HDF4. HDF4 access is read-only.
 *
 * @author Ed Hartnett
 */

#include "config.h"
#include <stdlib.h>
#include "hdf4dispatch.h"
#include "nc4dispatch.h"
#include "nc.h"

/* This is the dispatch object that holds pointers to all the
 * functions that make up the HDF4 dispatch interface. */
static NC_Dispatch HDF4_dispatcher = {

NC_FORMATX_NC_HDF4,

RO_create,
HDF4_open,

RO_redef,
RO__enddef,
RO_sync,
HDF4_abort,
HDF4_close,
RO_set_fill,
HDF4_inq_base_pe,
HDF4_set_base_pe,
HDF4_inq_format,
HDF4_inq_format_extended,

NC4_inq,
NC4_inq_type,

RO_def_dim,
NC4_inq_dimid,
NC4_inq_dim,
NC4_inq_unlimdim,
RO_rename_dim,

NC4_inq_att,
NC4_inq_attid,
NC4_inq_attname,
RO_rename_att,
RO_del_att,
NC4_get_att,
RO_put_att,

RO_def_var,
NC4_inq_varid,
RO_rename_var,
HDF4_get_vara,
RO_put_vara,
NCDEFAULT_get_vars,
NCDEFAULT_put_vars,
NCDEFAULT_get_varm,
NCDEFAULT_put_varm,

NC4_inq_var_all,

HDF4_var_par_access,
RO_def_var_fill,

NC4_show_metadata,
NC4_inq_unlimdims,

NC4_inq_ncid,
NC4_inq_grps,
NC4_inq_grpname,
NC4_inq_grpname_full,
NC4_inq_grp_parent,
NC4_inq_grp_full_ncid,
NC4_inq_varids,
NC4_inq_dimids,
NC4_inq_typeids,
NC4_inq_type_equal,
HDF4_def_grp,
HDF4_rename_grp,
NC4_inq_user_type,
NC4_inq_typeid,

HDF4_def_compound,
HDF4_insert_compound,
HDF4_insert_array_compound,
HDF4_inq_compound_field,
HDF4_inq_compound_fieldindex,
HDF4_def_vlen,
HDF4_put_vlen_element,
HDF4_get_vlen_element,
HDF4_def_enum,
HDF4_insert_enum,
HDF4_inq_enum_member,
HDF4_inq_enum_ident,
HDF4_def_opaque,
HDF4_def_var_deflate,
HDF4_def_var_fletcher32,
HDF4_def_var_chunking,
HDF4_def_var_endian,
NONC4_def_var_filter,
HDF4_set_var_chunk_cache,
HDF4_get_var_chunk_cache,

};

NC_Dispatch* HDF4_dispatch_table = NULL;

/**
 * @internal Initialize HDF4 dispatch layer.
 *
 * @return ::NC_NOERR No error.
 * @author Ed Hartnett
 */
int
HDF4_initialize(void)
{
    HDF4_dispatch_table = &HDF4_dispatcher;
    return NC_NOERR;
}

/**
 * @internal Finalize HDF4 dispatch layer.
 *
 * @return ::NC_NOERR No error.
 * @author Ed Hartnett
 */
int
HDF4_finalize(void)
{
    return NC_NOERR;
}
