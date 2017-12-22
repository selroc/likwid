/*
 * =======================================================================================
 *
 *      Filename:  perfmon_sandybridge_counters.h
 *
 *      Description: Counter header file of perfmon module for Intel Sandy Bridge.
 *
 *      Version:   4.3.0
 *      Released:  22.12.2017
 *
 *      Author:   Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2017 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */


#define NUM_COUNTERS_CORE_SANDYBRIDGE 12
#define NUM_COUNTERS_UNCORE_SANDYBRIDGE 15
#define NUM_COUNTERS_SANDYBRIDGE 27

#define SNB_VALID_OPTIONS_FIXED EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_ANYTHREAD_MASK
#define SNB_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK| \
                            EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define SNB_VALID_OPTIONS_CBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK
#define SNB_VALID_OPTIONS_UBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK


static RegisterMap sandybridge_counter_map[NUM_COUNTERS_SANDYBRIDGE] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, SNB_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, SNB_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, SNB_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, SNB_VALID_OPTIONS_PMC},
    /* Additional PMC Counters: 4 48bit wide if HyperThreading is disabled*/
    {"PMC4", PMC7, PMC, MSR_PERFEVTSEL4, MSR_PMC4, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC5", PMC8, PMC, MSR_PERFEVTSEL5, MSR_PMC5, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC6", PMC9, PMC, MSR_PERFEVTSEL6, MSR_PMC6, 0, 0, SNB_VALID_OPTIONS_PMC},
    {"PMC7", PMC10, PMC, MSR_PERFEVTSEL7, MSR_PMC7, 0, 0, SNB_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC11, THERMAL, 0, IA32_THERM_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC12, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC13, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC14, POWER, 0, MSR_PP1_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC15, POWER, 0, MSR_DRAM_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"CBOX0C0", PMC16, CBOX0, MSR_UNC_CBO_0_PERFEVTSEL0, MSR_UNC_CBO_0_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC17, CBOX0, MSR_UNC_CBO_0_PERFEVTSEL1, MSR_UNC_CBO_0_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC18, CBOX1, MSR_UNC_CBO_1_PERFEVTSEL0, MSR_UNC_CBO_1_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC19, CBOX1, MSR_UNC_CBO_1_PERFEVTSEL1, MSR_UNC_CBO_1_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_CBO_2_PERFEVTSEL0, MSR_UNC_CBO_2_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_CBO_2_PERFEVTSEL1, MSR_UNC_CBO_2_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC22, CBOX3, MSR_UNC_CBO_3_PERFEVTSEL0, MSR_UNC_CBO_3_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC23, CBOX3, MSR_UNC_CBO_3_PERFEVTSEL1, MSR_UNC_CBO_3_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"UBOX0", PMC24, UBOX, MSR_UNC_ARB_PERFEVTSEL0, MSR_UNC_ARB_CTR0, 0, 0, SNB_VALID_OPTIONS_UBOX},
    {"UBOX1", PMC25, UBOX, MSR_UNC_ARB_PERFEVTSEL1, MSR_UNC_ARB_CTR1, 0, 0, SNB_VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC26, UBOXFIX, MSR_UNC_PERF_FIXED_CTRL, MSR_UNC_PERF_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
};

static BoxMap sandybridge_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, MSR_DEV, 48},
    [FIXED] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, MSR_DEV, 48},
    [THERMAL] = {0, 0, 0, 0, 0, MSR_DEV, 8},
    [POWER] = {0, 0, 0, 0, 0, MSR_DEV, 32},
    [CBOX0] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 3, 0, MSR_DEV, 44},
    [CBOX1] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 3, 0, MSR_DEV, 44},
    [CBOX2] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 3, 0, MSR_DEV, 44},
    [CBOX3] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 3, 0, MSR_DEV, 44},
    [UBOX] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 1, 0, MSR_DEV, 44},
    [UBOXFIX] = {MSR_UNC_PERF_GLOBAL_CTRL, MSR_UNC_PERF_GLOBAL_STATUS, MSR_UNC_PERF_GLOBAL_OVF_CTRL, 0, 0, MSR_DEV, 44},
};



