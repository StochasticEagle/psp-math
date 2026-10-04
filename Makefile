TARGET_LIB = bin/psp-math.a

# PSPSDK native variables
INCDIR = include
BUILD_DIR = build
SRC_DIR = src
BIN_DIR = bin

# List all source files residing in src/
SRCS = \
    printMatrixFloat.o  \
    VecOps.s  \
    vfpu_acosf.o  \
    vfpu_add_vector.o  \
    vfpu_asinf.o  \
    vfpu_atanf.o  \
    vfpu_cosf.o  \
    vfpu_coshf.o  \
    vfpu_distance.o  \
    vfpu_ease_in_out.o  \
    vfpu_envmap_matrix.o  \
    vfpu_expf.o  \
    vfpu_fabsf.o  \
    vfpu_fmaxf.o  \
    vfpu_fminf.o  \
    vfpu_fmodf.o  \
    vfpu_identity_matrix.o  \
    vfpu_logf.o  \
    vfpu_look_at_matrix.o  \
    vfpu_normalize_vector.o  \
    vfpu_ortho_matrix.o  \
    vfpu_perspective_matrix.o  \
    vfpu_powf.o  \
    vfpu_quaternion_copy.o  \
    vfpu_quaternion_exp.o  \
    vfpu_quaternion_from_euler.o  \
    vfpu_quaternion_hermite_tangent.o  \
    vfpu_quaternion_identity.o  \
    vfpu_quaternion_ln.o  \
    vfpu_quaternion_multiply.o  \
    vfpu_quaternion_normalize.o  \
    vfpu_quaternion_sample_hermite.o  \
    vfpu_quaternion_sample_linear.o  \
    vfpu_quaternion_to_matrix.o  \
    vfpu_rand_8888.o  \
    vfpu_randf.o  \
    vfpu_scale_vector.o  \
    vfpu_sincos.o  \
    vfpu_sinf.o  \
    vfpu_sinhf.o  \
    vfpu_sphere_to_cartesian.o  \
    vfpu_sqrtf.o  \
    vfpu_srand.o  \
    vfpu_tanf.o  \
    vfpu_tanhf.o  \
    vfpu_translate_matrix.o  \
    vfpu_zero_vector.o

OBJS = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

PSPSDK = $(shell psp-config --pspsdk-path)

# Ensure directories exist before build.mak targets are evaluated
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

all: $(TARGET_LIB)
	@echo "Successfully built $(TARGET_LIB)"

# Pattern rules directing compiler/assembler to pull from src/ and output to build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s
	$(AS) $(ASFLAGS) -I$(INCDIR) -c $< -o $@

# Let PSPSDK build.mak handle archiving directly into bin/psp-math.a
include $(PSPSDK)/lib/build.mak

#clean:
#	@rm -rf $(BUILD_DIR) $(BIN_DIR)

install: $(TARGET_LIB)
	@echo "Installing library to $(PSPSDK)/lib..."
	@cp $(TARGET_LIB) $(PSPSDK)/lib
	@cp $(INCDIR)/pspmath.h $(PSPSDK)/include
