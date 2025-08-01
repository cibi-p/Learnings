/*

    EGL loader generated by glad 0.1.36 on Fri Aug 30 12:26:00 2024.

    Language/Generator: C/C++
    Specification: egl
    APIs: egl=1.5
    Profile: -
    Extensions:
        EGL_EXT_image_dma_buf_import,
        EGL_EXT_image_dma_buf_import_modifiers,
        EGL_EXT_image_gl_colorspace,
        EGL_EXT_image_implicit_sync_control,
        EGL_MESA_drm_image,
        EGL_MESA_image_dma_buf_export,
        EGL_MESA_platform_gbm,
        EGL_MESA_platform_surfaceless,
        EGL_MESA_query_driver
    Loader: True
    Local files: False
    Omit khrplatform: False
    Reproducible: False

    Commandline:
        --api="egl=1.5" --generator="c" --spec="egl" --extensions="EGL_EXT_image_dma_buf_import,EGL_EXT_image_dma_buf_import_modifiers,EGL_EXT_image_gl_colorspace,EGL_EXT_image_implicit_sync_control,EGL_MESA_drm_image,EGL_MESA_image_dma_buf_export,EGL_MESA_platform_gbm,EGL_MESA_platform_surfaceless,EGL_MESA_query_driver"
    Online:
        https://glad.dav1d.de/#language=c&specification=egl&loader=on&api=egl%3D1.5&extensions=EGL_EXT_image_dma_buf_import&extensions=EGL_EXT_image_dma_buf_import_modifiers&extensions=EGL_EXT_image_gl_colorspace&extensions=EGL_EXT_image_implicit_sync_control&extensions=EGL_MESA_drm_image&extensions=EGL_MESA_image_dma_buf_export&extensions=EGL_MESA_platform_gbm&extensions=EGL_MESA_platform_surfaceless&extensions=EGL_MESA_query_driver
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/glad/glad_egl.h"

int gladLoadEGL(void) {
    return gladLoadEGLLoader((GLADloadproc)eglGetProcAddress);
}

PFNEGLQUERYDMABUFFORMATSEXTPROC glad_eglQueryDmaBufFormatsEXT = NULL;
PFNEGLQUERYDMABUFMODIFIERSEXTPROC glad_eglQueryDmaBufModifiersEXT = NULL;
PFNEGLCREATEDRMIMAGEMESAPROC glad_eglCreateDRMImageMESA = NULL;
PFNEGLEXPORTDRMIMAGEMESAPROC glad_eglExportDRMImageMESA = NULL;
PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC glad_eglExportDMABUFImageQueryMESA = NULL;
PFNEGLEXPORTDMABUFIMAGEMESAPROC glad_eglExportDMABUFImageMESA = NULL;
PFNEGLGETDISPLAYDRIVERCONFIGPROC glad_eglGetDisplayDriverConfig = NULL;
PFNEGLGETDISPLAYDRIVERNAMEPROC glad_eglGetDisplayDriverName = NULL;
static void load_EGL_EXT_image_dma_buf_import_modifiers(GLADloadproc load) {
	glad_eglQueryDmaBufFormatsEXT = (PFNEGLQUERYDMABUFFORMATSEXTPROC)load("eglQueryDmaBufFormatsEXT");
	glad_eglQueryDmaBufModifiersEXT = (PFNEGLQUERYDMABUFMODIFIERSEXTPROC)load("eglQueryDmaBufModifiersEXT");
}
static void load_EGL_MESA_drm_image(GLADloadproc load) {
	glad_eglCreateDRMImageMESA = (PFNEGLCREATEDRMIMAGEMESAPROC)load("eglCreateDRMImageMESA");
	glad_eglExportDRMImageMESA = (PFNEGLEXPORTDRMIMAGEMESAPROC)load("eglExportDRMImageMESA");
}
static void load_EGL_MESA_image_dma_buf_export(GLADloadproc load) {
	glad_eglExportDMABUFImageQueryMESA = (PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC)load("eglExportDMABUFImageQueryMESA");
	glad_eglExportDMABUFImageMESA = (PFNEGLEXPORTDMABUFIMAGEMESAPROC)load("eglExportDMABUFImageMESA");
}
static void load_EGL_MESA_query_driver(GLADloadproc load) {
	glad_eglGetDisplayDriverConfig = (PFNEGLGETDISPLAYDRIVERCONFIGPROC)load("eglGetDisplayDriverConfig");
	glad_eglGetDisplayDriverName = (PFNEGLGETDISPLAYDRIVERNAMEPROC)load("eglGetDisplayDriverName");
}
static int find_extensionsEGL(void) {
	return 1;
}

static void find_coreEGL(void) {
}

int gladLoadEGLLoader(GLADloadproc load) {
	(void) load;
	find_coreEGL();

	if (!find_extensionsEGL()) return 0;
	load_EGL_EXT_image_dma_buf_import_modifiers(load);
	load_EGL_MESA_drm_image(load);
	load_EGL_MESA_image_dma_buf_export(load);
	load_EGL_MESA_query_driver(load);
	return 1;
}

