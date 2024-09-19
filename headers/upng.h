#ifndef UPNG_H
#define UPNG_H

/**
 * uPNG - A lightweight PNG decoder derived from LodePNG (version 20100808).
 *
 * Copyright (c) 2005-2010 Lode Vandevenne
 * Copyright (c) 2010 Sean Middleditch
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * The authors are not liable for any damages arising from the use of this software.
 *
 * Permission is granted to use this software for any purpose, including commercial applications,
 * and to alter and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote
 *    the original software. An acknowledgment in the product documentation is appreciated but not required.
 *
 * 2. Altered source versions must be plainly marked as such and must not be misrepresented
 *    as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

// Enum for error codes returned by uPNG functions
typedef enum upng_error
{
    UPNG_EOK           = 0, // Success: no error occurred
    UPNG_ENOMEM        = 1, // Memory allocation failed
    UPNG_ENOTFOUND     = 2, // Resource not found (e.g., file missing)
    UPNG_ENOTPNG       = 3, // Image data does not have a valid PNG header
    UPNG_EMALFORMED    = 4, // Image data is not a valid PNG image
    UPNG_EUNSUPPORTED   = 5, // Critical PNG chunk type is not supported
    UPNG_EUNINTERLACED = 6, // Image interlacing is not supported
    UPNG_EUNFORMAT     = 7, // Image color format is not supported
    UPNG_EPARAM        = 8  // Invalid parameter provided to method call
} upng_error;

// Enum for supported image formats
typedef enum upng_format
{
    UPNG_BADFORMAT,        // Unrecognized format
    UPNG_RGB8,            // 8-bit RGB format
    UPNG_RGB16,           // 16-bit RGB format
    UPNG_RGBA8,           // 8-bit RGBA format
    UPNG_RGBA16,          // 16-bit RGBA format
    UPNG_LUMINANCE1,      // 1-bit grayscale
    UPNG_LUMINANCE2,      // 2-bit grayscale
    UPNG_LUMINANCE4,      // 4-bit grayscale
    UPNG_LUMINANCE8,      // 8-bit grayscale
    UPNG_LUMINANCE_ALPHA1, // 1-bit grayscale with alpha
    UPNG_LUMINANCE_ALPHA2, // 2-bit grayscale with alpha
    UPNG_LUMINANCE_ALPHA4, // 4-bit grayscale with alpha
    UPNG_LUMINANCE_ALPHA8   // 8-bit grayscale with alpha
} upng_format;

// Opaque structure for PNG data
typedef struct upng_t upng_t;

// Creates a new uPNG instance from a byte buffer
upng_t *upng_new_from_bytes(const unsigned char *buffer, unsigned long size);

// Creates a new uPNG instance from a file
upng_t *upng_new_from_file(const char *path);

// Frees the resources associated with a uPNG instance
void upng_free(upng_t *upng);

// Reads the PNG header and retrieves basic information
upng_error upng_header(upng_t *upng);

// Decodes the PNG image data into a usable format
upng_error upng_decode(upng_t *upng);

// Returns the last error code encountered
upng_error upng_get_error(const upng_t *upng);

// Returns the line number where the last error occurred
unsigned int upng_get_error_line(const upng_t *upng);

// Retrieves the width of the decoded PNG image
unsigned int upng_get_width(const upng_t *upng);

// Retrieves the height of the decoded PNG image
unsigned int upng_get_height(const upng_t *upng);

// Retrieves the bits per pixel of the decoded PNG image
unsigned int upng_get_bpp(const upng_t *upng);

// Retrieves the bit depth of the decoded PNG image
unsigned int upng_get_bitdepth(const upng_t *upng);

// Retrieves the number of color components in the decoded PNG image
unsigned int upng_get_components(const upng_t *upng);

// Retrieves the size of a single pixel in bytes
unsigned int upng_get_pixelsize(const upng_t *upng);

// Retrieves the format of the decoded PNG image
upng_format upng_get_format(const upng_t *upng);

// Retrieves a pointer to the raw pixel buffer of the decoded PNG image
const unsigned char *upng_get_buffer(const upng_t *upng);

// Retrieves the size of the raw pixel buffer
unsigned int upng_get_size(const upng_t *upng);

#endif /* defined(UPNG_H) */
