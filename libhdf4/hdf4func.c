/* Copyright 2018, UCAR/Unidata See netcdf/COPYRIGHT file for copying
 * and redistribution conditions.*/
/**
 * @file @internal HDF4 functions.
 *
 * @author Ed Hartnett
 */

#include "config.h"
#include <errno.h>  /* netcdf functions sometimes return system errors */
#include "nc.h"
#include "nc4internal.h"
#include "hdf4dispatch.h"
#include <mfhdf.h>

/**
 * @internal Get the format (i.e. NC_FORMAT_NC_HDF4) of an open HDF4
 * file.
 *
 * @param ncid File ID (ignored).
 * @param formatp Pointer that gets the constant indicating format.

 * @return ::NC_NOERR No error.
 * @return ::NC_EBADID Bad ncid.
 * @author Ed Hartnett
 */
int
HDF4_inq_format(int ncid, int *formatp)
{
   LOG((2, "nc_inq_format: ncid 0x%x", ncid));

   if (!formatp)
      return NC_NOERR;

   /* HDF4 is the format. */
   *formatp = NC_FORMATX_NC_HDF4;

   return NC_NOERR;
}

/**
 * @internal Return the extended format (i.e. the dispatch model),
 * plus the mode associated with an open file.
 *
 * @param ncid File ID (ignored).
 * @param formatp a pointer that gets the extended format. Note that
 * this is not the same as the format provided by nc_inq_format(). The
 * extended foramt indicates the dispatch layer model. HDF4 files
 * will always get NC_FORMATX_NC_HDF4.
 * @param modep a pointer that gets the open/create mode associated with
 * this file. Ignored if NULL.

 * @return ::NC_NOERR No error.
 * @return ::NC_EBADID Bad ncid.
 * @author Ed Hartnett
 */
int
HDF4_inq_format_extended(int ncid, int *formatp, int *modep)
{
   NC *nc;
   NC_HDF5_FILE_INFO_T* h5;

   LOG((2, "%s: ncid 0x%x", __func__, ncid));

   if (!(nc = nc4_find_nc_file(ncid, &h5)))
      return NC_EBADID;

   if (modep)
      *modep = (nc->mode|NC_NETCDF4);

   if (formatp) 
      *formatp = NC_FORMATX_NC_HDF4;
   
   return NC_NOERR;
}
