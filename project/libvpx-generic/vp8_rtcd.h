#ifndef VP8_RTCD_H_
#define VP8_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * VP8
 */

struct blockd;
struct macroblockd;
struct loop_filter_info;

/* Encoder forward decls */
struct block;
struct macroblock;
struct variance_vtable;
union int_mv;
struct yv12_buffer_config;

#ifdef __cplusplus
extern "C" {
#endif

void vp8_bilinear_predict16x16_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict16x16_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict16x16_sse2(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict16x16_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_bilinear_predict16x16)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_bilinear_predict4x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict4x4_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict4x4 vp8_bilinear_predict4x4_c

void vp8_bilinear_predict8x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x4_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
#define vp8_bilinear_predict8x4 vp8_bilinear_predict8x4_c

void vp8_bilinear_predict8x8_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x8_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x8_sse2(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_bilinear_predict8x8_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_bilinear_predict8x8)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_blend_b_c(unsigned char *y, unsigned char *u, unsigned char *v, int y1, int u1, int v1, int alpha, int stride);
#define vp8_blend_b vp8_blend_b_c

void vp8_blend_mb_inner_c(unsigned char *y, unsigned char *u, unsigned char *v, int y1, int u1, int v1, int alpha, int stride);
#define vp8_blend_mb_inner vp8_blend_mb_inner_c

void vp8_blend_mb_outer_c(unsigned char *y, unsigned char *u, unsigned char *v, int y1, int u1, int v1, int alpha, int stride);
#define vp8_blend_mb_outer vp8_blend_mb_outer_c

void vp8_build_intra_predictors_mbuv_s_c(struct macroblockd *x, unsigned char * uabove_row, unsigned char * vabove_row,  unsigned char *uleft, unsigned char *vleft, int left_stride, unsigned char * upred_ptr, unsigned char * vpred_ptr, int pred_stride);
void vp8_build_intra_predictors_mbuv_s_sse2(struct macroblockd *x, unsigned char * uabove_row, unsigned char * vabove_row,  unsigned char *uleft, unsigned char *vleft, int left_stride, unsigned char * upred_ptr, unsigned char * vpred_ptr, int pred_stride);
void vp8_build_intra_predictors_mbuv_s_ssse3(struct macroblockd *x, unsigned char * uabove_row, unsigned char * vabove_row,  unsigned char *uleft, unsigned char *vleft, int left_stride, unsigned char * upred_ptr, unsigned char * vpred_ptr, int pred_stride);
RTCD_EXTERN void (*vp8_build_intra_predictors_mbuv_s)(struct macroblockd *x, unsigned char * uabove_row, unsigned char * vabove_row,  unsigned char *uleft, unsigned char *vleft, int left_stride, unsigned char * upred_ptr, unsigned char * vpred_ptr, int pred_stride);

void vp8_build_intra_predictors_mby_s_c(struct macroblockd *x, unsigned char * yabove_row, unsigned char * yleft, int left_stride, unsigned char * ypred_ptr, int y_stride);
void vp8_build_intra_predictors_mby_s_sse2(struct macroblockd *x, unsigned char * yabove_row, unsigned char * yleft, int left_stride, unsigned char * ypred_ptr, int y_stride);
void vp8_build_intra_predictors_mby_s_ssse3(struct macroblockd *x, unsigned char * yabove_row, unsigned char * yleft, int left_stride, unsigned char * ypred_ptr, int y_stride);
RTCD_EXTERN void (*vp8_build_intra_predictors_mby_s)(struct macroblockd *x, unsigned char * yabove_row, unsigned char * yleft, int left_stride, unsigned char * ypred_ptr, int y_stride);

void vp8_clear_system_state_c();
void vpx_reset_mmx_state();
#define vp8_clear_system_state vp8_clear_system_state_c

void vp8_copy_mem16x16_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem16x16_mmx(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem16x16_sse2(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem16x16 vp8_copy_mem16x16_c

void vp8_copy_mem8x4_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem8x4_mmx(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem8x4 vp8_copy_mem8x4_c

void vp8_copy_mem8x8_c(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
void vp8_copy_mem8x8_mmx(unsigned char *src, int src_pitch, unsigned char *dst, int dst_pitch);
#define vp8_copy_mem8x8 vp8_copy_mem8x8_c

void vp8_dc_only_idct_add_c(short input, unsigned char *pred, int pred_stride, unsigned char *dst, int dst_stride);
void vp8_dc_only_idct_add_mmx(short input, unsigned char *pred, int pred_stride, unsigned char *dst, int dst_stride);
#define vp8_dc_only_idct_add vp8_dc_only_idct_add_c

void vp8_dequant_idct_add_c(short *input, short *dq, unsigned char *output, int stride);
void vp8_dequant_idct_add_mmx(short *input, short *dq, unsigned char *output, int stride);
#define vp8_dequant_idct_add vp8_dequant_idct_add_c

void vp8_dequant_idct_add_uv_block_c(short *q, short *dq, unsigned char *dst_u, unsigned char *dst_v, int stride, char *eobs);
void vp8_dequant_idct_add_uv_block_mmx(short *q, short *dq, unsigned char *dst_u, unsigned char *dst_v, int stride, char *eobs);
void vp8_dequant_idct_add_uv_block_sse2(short *q, short *dq, unsigned char *dst_u, unsigned char *dst_v, int stride, char *eobs);
#define vp8_dequant_idct_add_uv_block vp8_dequant_idct_add_uv_block_c

void vp8_dequant_idct_add_y_block_c(short *q, short *dq, unsigned char *dst, int stride, char *eobs);
void vp8_dequant_idct_add_y_block_mmx(short *q, short *dq, unsigned char *dst, int stride, char *eobs);
void vp8_dequant_idct_add_y_block_sse2(short *q, short *dq, unsigned char *dst, int stride, char *eobs);
#define vp8_dequant_idct_add_y_block vp8_dequant_idct_add_y_block_c

void vp8_dequantize_b_c(struct blockd*, short *dqc);
void vp8_dequantize_b_mmx(struct blockd*, short *dqc);
#define vp8_dequantize_b vp8_dequantize_b_c

void vp8_filter_by_weight16x16_c(unsigned char *src, int src_stride, unsigned char *dst, int dst_stride, int src_weight);
void vp8_filter_by_weight16x16_sse2(unsigned char *src, int src_stride, unsigned char *dst, int dst_stride, int src_weight);
#define vp8_filter_by_weight16x16 vp8_filter_by_weight16x16_c

void vp8_filter_by_weight4x4_c(unsigned char *src, int src_stride, unsigned char *dst, int dst_stride, int src_weight);
#define vp8_filter_by_weight4x4 vp8_filter_by_weight4x4_c

void vp8_filter_by_weight8x8_c(unsigned char *src, int src_stride, unsigned char *dst, int dst_stride, int src_weight);
void vp8_filter_by_weight8x8_sse2(unsigned char *src, int src_stride, unsigned char *dst, int dst_stride, int src_weight);
#define vp8_filter_by_weight8x8 vp8_filter_by_weight8x8_c

void vp8_intra4x4_predict_c(unsigned char *Above, unsigned char *yleft, int left_stride, int b_mode, unsigned char *dst, int dst_stride, unsigned char top_left);
#define vp8_intra4x4_predict vp8_intra4x4_predict_c

void vp8_loop_filter_bh_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bh_mmx(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bh_sse2(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_bh vp8_loop_filter_bh_c

void vp8_loop_filter_bv_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bv_mmx(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_bv_sse2(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_bv vp8_loop_filter_bv_c

void vp8_loop_filter_mbh_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbh_mmx(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbh_sse2(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_mbh vp8_loop_filter_mbh_c

void vp8_loop_filter_mbv_c(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbv_mmx(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
void vp8_loop_filter_mbv_sse2(unsigned char *y, unsigned char *u, unsigned char *v, int ystride, int uv_stride, struct loop_filter_info *lfi);
#define vp8_loop_filter_mbv vp8_loop_filter_mbv_c

void vp8_loop_filter_bhs_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bhs_mmx(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bhs_sse2(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_bh vp8_loop_filter_bhs_c

void vp8_loop_filter_bvs_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bvs_mmx(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_bvs_sse2(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_bv vp8_loop_filter_bvs_c

void vp8_loop_filter_simple_horizontal_edge_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_horizontal_edge_mmx(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_horizontal_edge_sse2(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_mbh vp8_loop_filter_simple_horizontal_edge_c

void vp8_loop_filter_simple_vertical_edge_c(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_vertical_edge_mmx(unsigned char *y, int ystride, const unsigned char *blimit);
void vp8_loop_filter_simple_vertical_edge_sse2(unsigned char *y, int ystride, const unsigned char *blimit);
#define vp8_loop_filter_simple_mbv vp8_loop_filter_simple_vertical_edge_c

void vp8_mbpost_proc_across_ip_c(unsigned char *dst, int pitch, int rows, int cols,int flimit);
void vp8_mbpost_proc_across_ip_xmm(unsigned char *dst, int pitch, int rows, int cols,int flimit);
#define vp8_mbpost_proc_across_ip vp8_mbpost_proc_across_ip_c

void vp8_mbpost_proc_down_c(unsigned char *dst, int pitch, int rows, int cols,int flimit);
void vp8_mbpost_proc_down_mmx(unsigned char *dst, int pitch, int rows, int cols,int flimit);
void vp8_mbpost_proc_down_xmm(unsigned char *dst, int pitch, int rows, int cols,int flimit);
#define vp8_mbpost_proc_down vp8_mbpost_proc_down_c

void vp8_plane_add_noise_c(unsigned char *s, char *noise, char blackclamp[16], char whiteclamp[16], char bothclamp[16], unsigned int w, unsigned int h, int pitch);
void vp8_plane_add_noise_mmx(unsigned char *s, char *noise, char blackclamp[16], char whiteclamp[16], char bothclamp[16], unsigned int w, unsigned int h, int pitch);
void vp8_plane_add_noise_wmt(unsigned char *s, char *noise, char blackclamp[16], char whiteclamp[16], char bothclamp[16], unsigned int w, unsigned int h, int pitch);
#define vp8_plane_add_noise vp8_plane_add_noise_c

void vp8_post_proc_down_and_across_mb_row_c(unsigned char *src, unsigned char *dst, int src_pitch, int dst_pitch, int cols, unsigned char *flimits, int size);
void vp8_post_proc_down_and_across_mb_row_sse2(unsigned char *src, unsigned char *dst, int src_pitch, int dst_pitch, int cols, unsigned char *flimits, int size);
#define vp8_post_proc_down_and_across_mb_row vp8_post_proc_down_and_across_mb_row_c

void vp8_short_idct4x4llm_c(short *input, unsigned char *pred, int pitch, unsigned char *dst, int dst_stride);
void vp8_short_idct4x4llm_mmx(short *input, unsigned char *pred, int pitch, unsigned char *dst, int dst_stride);
#define vp8_short_idct4x4llm vp8_short_idct4x4llm_c

void vp8_short_inv_walsh4x4_c(short *input, short *output);
void vp8_short_inv_walsh4x4_mmx(short *input, short *output);
void vp8_short_inv_walsh4x4_sse2(short *input, short *output);
#define vp8_short_inv_walsh4x4 vp8_short_inv_walsh4x4_c

void vp8_short_inv_walsh4x4_1_c(short *input, short *output);
#define vp8_short_inv_walsh4x4_1 vp8_short_inv_walsh4x4_1_c

void vp8_sixtap_predict16x16_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict16x16_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict16x16_sse2(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict16x16_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_sixtap_predict16x16)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_sixtap_predict4x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict4x4_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict4x4_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_sixtap_predict4x4)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_sixtap_predict8x4_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x4_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x4_sse2(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x4_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_sixtap_predict8x4)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_sixtap_predict8x8_c(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x8_mmx(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x8_sse2(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
void vp8_sixtap_predict8x8_ssse3(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);
RTCD_EXTERN void (*vp8_sixtap_predict8x8)(unsigned char *src, int src_pitch, int xofst, int yofst, unsigned char *dst, int dst_pitch);

void vp8_rtcd(void);

#ifdef RTCD_C
//#include "vpx_ports/x86.h"
static void setup_rtcd_internal(void)
{
    //int flags = x86_simd_caps();

    //(void)flags;

    vp8_bilinear_predict16x16 = vp8_bilinear_predict16x16_c;
    //vp8_bilinear_predict16x16 = vp8_bilinear_predict16x16_sse2;
    //if (flags & HAS_SSSE3) vp8_bilinear_predict16x16 = vp8_bilinear_predict16x16_ssse3;
    vp8_bilinear_predict8x8 = vp8_bilinear_predict8x8_c;
    //vp8_bilinear_predict8x8 = vp8_bilinear_predict8x8_sse2;
    //if (flags & HAS_SSSE3) vp8_bilinear_predict8x8 = vp8_bilinear_predict8x8_ssse3;
    vp8_build_intra_predictors_mbuv_s = vp8_build_intra_predictors_mbuv_s_c;
    //vp8_build_intra_predictors_mbuv_s = vp8_build_intra_predictors_mbuv_s_sse2;
    //if (flags & HAS_SSSE3) vp8_build_intra_predictors_mbuv_s = vp8_build_intra_predictors_mbuv_s_ssse3;
    vp8_build_intra_predictors_mby_s = vp8_build_intra_predictors_mby_s_c;
    //vp8_build_intra_predictors_mby_s = vp8_build_intra_predictors_mby_s_sse2;
    //if (flags & HAS_SSSE3) vp8_build_intra_predictors_mby_s = vp8_build_intra_predictors_mby_s_ssse3;
    vp8_sixtap_predict16x16 = vp8_sixtap_predict16x16_c;
    //vp8_sixtap_predict16x16 = vp8_sixtap_predict16x16_sse2;
    //if (flags & HAS_SSSE3) vp8_sixtap_predict16x16 = vp8_sixtap_predict16x16_ssse3;
    vp8_sixtap_predict4x4 = vp8_sixtap_predict4x4_c;
    //vp8_sixtap_predict4x4 = vp8_sixtap_predict4x4_mmx;
    //if (flags & HAS_SSSE3) vp8_sixtap_predict4x4 = vp8_sixtap_predict4x4_ssse3;
    vp8_sixtap_predict8x4 = vp8_sixtap_predict8x4_c;
    //vp8_sixtap_predict8x4 = vp8_sixtap_predict8x4_sse2;
    //if (flags & HAS_SSSE3) vp8_sixtap_predict8x4 = vp8_sixtap_predict8x4_ssse3;
    vp8_sixtap_predict8x8 = vp8_sixtap_predict8x8_c;
    //vp8_sixtap_predict8x8 = vp8_sixtap_predict8x8_sse2;
    //if (flags & HAS_SSSE3) vp8_sixtap_predict8x8 = vp8_sixtap_predict8x8_ssse3;
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
