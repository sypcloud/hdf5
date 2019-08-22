/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * Programmer:  Quincey Koziol <koziol@hdfgroup.org>
 *              Tuesday, January 8, 2008
 *
 * Purpose:     This file contains declarations which are visible only within
 *              the H5MV package.  Source files outside the H5MV package should
 *              include H5MVprivate.h instead.
 */
#if !(defined H5MV_FRIEND || defined H5MV_MODULE)
#error "Do not include this file outside the H5MV package!"
#endif

#ifndef _H5MVpkg_H
#define _H5MVpkg_H

/* Get package's private header */
#include "H5MVprivate.h"

/* Other private headers needed by this file */
#include "H5FSprivate.h"	/* File free space                      */


/**************************/
/* Package Private Macros */
/**************************/

/* Define this to display information about file allocations */
/* #define H5MV_VFD_SWMR_DEBUG */

/* Free-space section types for file */
/* (values stored in free space data structures in file) */
#define H5MV_FSPACE_SECT_SIMPLE     0   /* For non-paged aggregation: section is a range of actual bytes in file */

/****************************/
/* Package Private Typedefs */
/****************************/

/* File free space section info */
typedef struct H5MV_free_section_t {
    H5FS_section_info_t sect_info;              /* Free space section information (must be first in struct) */
} H5MV_free_section_t;

/*****************************/
/* Package Private Variables */
/*****************************/

/* H5MF single section inherits serializable properties from H5FS_section_class_t */
H5_DLLVAR H5FS_section_class_t H5MV_FSPACE_SECT_CLS_SIMPLE[1];


/******************************/
/* Package Private Prototypes */
/******************************/

H5_DLL htri_t H5MV__find_sect(H5F_t *f, hsize_t size, H5FS_t *fspace, haddr_t *addr);
H5_DLL herr_t H5MV__create(H5F_t *f);

/* free-space section routines */
H5_DLL H5MV_free_section_t *H5MV__sect_new(haddr_t sect_off, hsize_t sect_size);
H5_DLL herr_t H5MV__sect_free(H5FS_section_info_t *sect);
H5_DLL htri_t H5MV__sect_can_shrink(const H5FS_section_info_t *_sect, void *udata);
H5_DLL herr_t H5MV__sect_shrink(H5FS_section_info_t **_sect, void *udata);


/* Testing routines */
#ifdef H5MF_TESTING
#endif /* H5MF_TESTING */

#endif /* _H5MFpkg_H */
