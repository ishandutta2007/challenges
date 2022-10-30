/*

Create a function that takes an array arr and a number n and returns an array of two integers from arr whose product equals n.
Examples

twoProduct([1, 2, -1, 4, 5], 20) ➞ [4, 5]

twoProduct([1, 2, 3, 4, 5], 10) ➞ [2, 5]

twoProduct([100, 12, 4, 1, 2], 15) ➞ []

Note:

    Try doing this with 0(N) time complexity.
    No duplicates.
    In the array, there can be multiple solutions so return the solution with the lowest sum of indexes of product pairs (i.e. N = 10, solutions = [[2, 5], [10, 1]], indexes = [[600, 3000], [800, 900]], return [10, 1]).
    The array can have multiple solutions, so return the first full match that you have found.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, -1, 4, 5}, 20, []int{4, 5})
	test([]int{1, 2, 3, 4, 5}, 10, []int{2, 5})
	test([]int{100, 12, 4, 1, 2}, 15, []int{})
	test([]int{1, 2, -1, 4, 5}, 110, []int{})
	test([]int{4677, 5091, 7086, 7328, 9813, 5190, 1188, 844, 9461, 8611, 9352, 3787, 1007, 9166, 3050, 6125, 4085, 5938, 5795, 5476, 5616, 4161, 3319, 2870, 9517, 8250, 985, 1809, 540, 1956, 3443, 960, 2203, 6127, 2187, 2729, 2183, 2779, 7505, 5858, 1351, 2929, 5870, 936, 3917, 5663, 4284, 6922, 8938, 1301, 6281, 8160, 5910, 4802, 43, 8697, 4657, 4088, 602, 2332, 4093, 1036, 4439, 8832, 30, 562, 6155, 6900, 3672, 2348, 1636, 5164, 2019, 4274, 3686, 6679, 5483, 6407, 7778, 2320, 4201, 7144, 653, 5160, 8489, 7740, 6596, 6712, 7442, 6005, 3244, 2026, 1939, 1824, 2341, 9172, 2716, 2490, 6747, 2015, 7448, 7950, 1697, 6313, 4679, 2775, 6219, 5907, 2684, 3433, 5947, 4270, 7267, 9464, 9077, 6230, 4976, 7497, 7090, 8328, 6517, 2025, 898, 3168, 7977, 3828, 367, 8260, 333, 4819, 6668, 3816, 564, 232, 9667, 2630, 6903, 1647, 309, 6795, 5402, 2146, 8184, 483, 8917, 3352, 8964, 8517, 2646, 97, 5929, 4772, 9235, 1181, 5772, 5898, 7105, 5873, 5967, 7353, 8647, 3610, 5424, 9632, 1173, 8608, 9148, 3567, 4924, 2059, 8822, 8139, 7383, 9704, 2097, 7339, 5635, 8787, 2216, 4572, 7802, 5615, 6724, 8333, 9322, 6767, 1270, 4827, 1487, 5661, 6507, 7579, 3275, 5863, 7035, 5143, 4016, 7780, 6436, 3108, 6935, 707, 3027, 3803, 7545, 4854, 4332, 194, 7808, 3603, 6390, 7584, 4466, 8500, 2330, 72, 6699, 3517, 4055, 2166, 9428, 5141, 6428, 7173, 2321, 9663, 4400, 6855, 3011, 2466, 8439, 1145, 425, 3846, 6850, 2207, 4463, 6820, 3609, 1404, 2042, 8530, 4585, 5536, 1983, 8537, 1836, 3648, 4957, 8048, 4358, 23, 5357, 1615, 8955, 1910, 8320, 5148, 743, 491, 3403, 5621, 5173, 8975, 6122, 5295, 7663, 1812, 2425, 8835, 8962, 8230, 4312, 8134, 810, 7631, 8087, 7358, 4760, 7673, 5268, 5218, 6858, 409, 1900, 3743, 3166, 9922, 9722, 7043, 6746, 9245, 8531, 2997, 3417, 5637, 2360, 2020, 6241, 9196}, 16200, []int{540, 30})
	test([]int{5645, 2705, 2948, 2571, 8756, 938, 4007, 6914, 9741, 1702, 470, 873, 8953, 2657, 3080, 5571, 281, 7640, 5633, 9899, 3446, 4267, 2752, 7643, 2212, 7304, 1439, 7960, 715, 3129, 5909, 1887, 4383, 7486, 7107, 5639, 5285, 5120, 6423, 6932, 4438, 9645, 23,
		8109, 5158, 980, 151, 2845, 1152, 7426, 3593, 1081, 4708, 511, 5038, 2775, 8733, 7505, 1259, 6296, 6763, 7708, 545, 9258, 2134, 6437, 9093, 5354, 4179, 3379, 3353, 3105, 5318, 5124, 6273, 7855, 3781, 6019, 5125, 9783, 5668, 8674, 168, 4195, 4763, 7800, 6409, 8496, 1113, 2348, 3937, 5096, 1688, 6331, 495, 4641, 6235, 7511, 6199, 6424, 953, 9122, 7270, 6004, 5951, 6181, 2648, 6592, 3006, 8238, 6765, 7465, 7136, 8691, 3969, 7997, 8219, 1643, 189, 4039, 3705, 9548, 7279, 4729, 6176, 603, 7891, 3101, 3934, 1997, 5341, 367, 2578, 3823, 8142, 906, 9516, 9553, 7187, 960, 3706, 5766, 7291, 7932, 2313, 3462, 5262, 3232, 371, 5938, 8698, 9705, 4904, 5203, 1648, 803, 7957, 1900, 6611, 6207, 3275, 305, 579, 4084, 8387, 4806, 9740, 8207, 9844, 2640, 8569, 7094, 8754, 4587, 7329, 8305, 5542, 8530, 2883, 5066, 9124, 8898, 2687, 7778, 1317, 3002, 2298, 5721, 456, 4543, 840, 2153, 8511,
		7807, 8659, 1084, 8746, 4993, 2418, 247, 3030, 1468, 7920, 17, 6559, 1183, 1034, 739, 9177, 1626, 2768, 3039, 9208, 1449, 5470, 7444, 6260, 3541, 8942, 1368, 198, 5112, 7826, 1835, 689, 5581, 1813, 5259, 9965, 3037, 8790, 7939, 5228, 8748, 454, 1086, 8708, 6068, 9060, 6928, 3966, 957, 8527, 2256, 9408, 834, 6961, 6778, 4204, 7682, 8156, 3584, 4944, 4213, 5006, 8369, 8171, 6747, 3451, 1852, 8891, 405, 7942, 8802, 7795, 54, 1512, 7659, 5657, 7358, 8434, 8540, 9967, 9574, 4582, 2309, 534, 563, 9311, 1746, 8792, 6882, 1644, 5060, 1897, 9612, 985, 3023, 3262, 1022, 2834, 2575, 902, 1013, 1392, 6455, 4818, 3985, 1238, 990, 1670, 8886, 1473, 472, 1486, 5081, 9962, 5168, 4093, 4643, 1405, 3797, 8544, 7011, 4696, 5286, 7694, 4349, 5253, 5880, 3176, 1055,
		3747, 34, 4772, 3821, 8209, 6250, 9388, 2662, 4553, 2607, 8989, 1494, 4135, 584, 9807, 7085, 3444, 8213, 1434, 7846, 6453, 2843, 2303, 5500, 2453, 2886, 43, 4611, 7256, 3548, 3166, 8580, 2702, 4929, 5840, 428, 5053, 2325, 5711, 2336, 1756, 6712, 6270,
		6122, 3533, 6622, 2788, 2032, 3071, 542, 4579, 8878, 5663, 4627, 3259, 9456, 1125, 4114, 5390, 3748, 7036, 3719, 5323, 8978, 5025, 8896, 3276, 2509, 8263, 80, 8613, 5899, 8223, 9507, 3691, 3215, 9437, 2547, 98, 2599, 7116, 4593, 1818, 2802, 5235, 2277, 8609, 4324, 153, 9108, 7687, 8524, 8587, 2965, 9119, 3059, 4226, 5965, 6469, 5712, 9762, 6940, 224, 7335, 4044, 3465, 4063, 4398, 212, 72, 6154, 4967, 2797, 355, 8686, 171, 4781, 5150, 6206, 5728, 3307, 5099, 3744, 8912, 1096, 7362, 2063, 6801, 8356,
		9587, 3312, 9835, 7352, 6581, 3099, 7374, 9896, 1158, 9329, 3756, 6026, 5806, 6950, 4663, 1517, 741, 1769, 585, 9090, 7641, 2924, 2052, 2157, 2014, 2034, 6896, 3332, 1788, 1102, 8286, 544, 7670, 7617, 583, 8327, 1181, 5314, 7719, 7236, 4369, 3895, 4109, 1463, 1725, 7216, 633, 7130, 7586, 4691, 9800, 5480, 2533, 1768, 4675, 3231, 5108, 6770, 8682, 4146, 7985, 3112, 4312, 2840, 2626, 4170, 6749, 3740, 8985, 2502, 3862, 9411, 5940, 7257, 1253, 5539, 9680, 4064, 301, 2047, 7837, 7714, 4172, 9949, 3551,
		5782, 6383, 4994, 1305, 7850, 1365, 888, 5132, 2736, 837, 1153, 779, 5429, 5441, 4446, 1052, 2726, 7073, 4687, 9728, 6771, 4788, 2417, 1360, 3510, 9996, 4499, 1243, 6930, 473, 903, 161, 8570, 5582, 9032, 8799, 1987, 196, 7998, 4506, 7476, 4481, 8836, 316, 1804, 2956, 2730, 1273, 3429, 4616, 6709, 9334, 5327, 3804, 4558, 4069, 1920, 7764, 6677, 3088, 7501, 2819, 1173, 6837, 1613, 5162, 9867, 1426, 180, 9983, 8663, 6664, 5065, 9753, 5601, 9797, 4133, 178, 4652, 2954, 1176, 6617, 239, 5058, 7086, 9425, 513, 3167, 4803, 3699, 6894, 2181, 5617, 8628, 641, 5846, 1625, 8336, 514, 2520, 7408, 3034, 2170, 5530, 6380, 701, 3665, 6111, 9467, 6509, 4947, 720, 6288, 5366, 8818, 2437, 2022, 3739, 1021, 7922, 6196, 7271, 5825, 8837, 82, 5535, 6366, 2569, 858, 2140, 449, 4590, 3760, 8258, 5705, 8338, 2630, 2814, 6016, 4242, 3847, 4479, 1211, 975, 9633, 7248, 6243, 6345, 2816, 1622, 575, 6009, 1511, 8666, 6391, 4494, 6538, 5534, 174, 7494, 4639, 895, 9591, 6857, 8841, 3676, 9344, 3069, 526, 5701, 6727, 1693, 3151, 1131, 3070, 2588, 8303, 6058, 1098, 9036, 2053, 2131, 7090, 5812, 518, 1298, 8844, 883, 9632, 7635, 7050, 3192, 919, 6480, 7069, 6846, 6229, 204, 880, 8665, 5618, 2023, 1544, 4631, 8593, 4900, 8773, 4449, 8326, 629, 7224, 7160, 565, 7732, 4342, 9044, 8990, 587, 1467, 9606, 4459, 4424, 1077, 7907, 6005, 4871, 928, 3570, 6177, 2988, 3052, 2893, 3547, 2570, 1738, 7220, 4950, 391, 1165, 9735, 8461, 3320, 8991, 2790, 8433, 5295, 2628, 3834, 9084, 493, 3633, 4769, 5935, 8620, 5906, 9417, 4858, 1726,
		4715, 1393, 9141, 9111, 5970, 7132, 9214, 6481, 2398, 3905, 4528, 9539, 100, 5017, 7557, 4808, 8442, 3568, 3403, 6434, 9446, 9522, 5669, 5100, 7492, 132, 5784, 9901, 7522, 6949, 6416, 9077, 704, 5774, 9339, 2039, 6153, 8290, 8045, 7429, 1283, 5819, 4751, 5625, 2379, 6227, 969, 1190, 7401, 8420, 7938, 10, 2492, 4723, 757, 1757, 3050, 1161, 9995, 7995, 2177, 9696, 3046, 8769, 8084, 3803, 669, 4067, 8793, 512, 3979, 9470, 1216, 2035, 8424, 5115, 8512, 6190, 5799, 1866, 4527, 7767, 5169, 3323, 7724, 8714, 8150, 7868, 9428, 4859, 5998, 3581, 7626, 1736, 1555, 270, 467, 7440, 7515, 292, 737, 5394, 9168, 4732, 5257, 6033, 4524, 5861, 5506, 5508, 5807, 9412, 3024, 1409, 1504, 6278, 3915, 6836, 5482, 8066, 7082, 2658, 7035, 2369, 6785, 4621, 8579, 6644, 8961, 2513, 6279, 8933, 1872, 8222, 5962, 7765, 7402, 3114, 789, 1598, 9155, 8203, 1110, 1721, 6915, 9812, 1106, 1400, 2258, 958, 4074, 4451, 8850, 4937, 943, 7651, 4471, 7645, 1007, 4762, 4697, 9167, 14, 1252, 1873, 8003, 2829, 3346, 5768, 1787, 8110,
		5296, 8250, 4214, 4247, 5477, 1182, 7787, 1590, 3942, 9803, 7390, 5898, 4282, 4775, 4870, 73, 8030, 6775, 6565, 7762, 6274, 8407, 886, 9584, 1136, 8234, 4496, 9070, 9654, 8979, 7354, 6810, 5121, 6114, 1056, 6558, 3696, 2899, 9538, 3938, 1457, 6648, 6043, 124, 2541, 2787, 9830, 5531, 3130, 4578, 3959, 788, 2853, 466, 202, 1671, 3697, 9454, 8479, 4362, 5076, 3931, 3596, 9599, 2832, 8870, 4893, 5329, 9392, 7539, 7736, 5652, 4985, 6171, 6456, 6237, 1575, 8044, 2596, 4341, 6992, 8279, 9850, 5452, 9957, 5776, 4983, 3891, 7301, 2538, 2387, 7495, 3826, 262, 8368, 147, 7963, 3338, 7473, 7775, 9067, 5243, 3930, 1762, 8786, 2518, 3840, 6169, 7589, 3460, 2302, 3923, 9283, 9834, 7852, 8313, 4881, 9498, 8949, 4948, 9181, 7251, 208, 1672, 8057, 5201, 1737, 5367, 940, 1838, 2915, 2049, 6066, 2284, 4029, 9833, 4360, 9916, 2644, 1915, 6597, 3660, 7059, 6989, 5127, 8632, 9870, 9438, 6943, 6685, 9829, 7387, 2780, 7129, 2613, 937, 5888, 5393, 8019, 9396, 3865, 725, 1082, 1558, 4437, 9743, 2280, 181, 723, 7206, 5105, 6170, 4642, 4793, 645, 870, 413, 7321, 4108, 5204, 1775, 278, 7953, 4203, 1724, 6454, 5553, 9702, 5554, 4938, 7815, 6064, 8359, 3768, 2839, 3022, 1864, 4298, 6353, 7858, 1524, 5563, 8228, 6542, 5580, 138, 5167, 5504, 7443, 8097, 2750, 9259, 5788, 5592, 663, 7975, 211, 5543, 8284, 8101, 4941, 9774, 9224, 4791, 6912, 8463, 5217, 5057, 9641, 9178, 8381, 9006, 8249, 1675, 3493, 714, 5939, 8635, 2686, 1823, 2639, 1910, 6516, 1074, 1339, 1660, 935, 510, 8311, 1271, 6745, 7570, 2553, 9621, 733, 1966, 4031, 4144, 7665, 7541, 4648, 4035, 6828, 2461, 6843, 8146, 7923, 7163, 1224, 3608, 2805, 3673, 4701, 7965, 6628, 3947, 7287, 1151, 8310, 4957, 3190, 48, 2937, 5839, 2283, 2652, 3588, 9804, 2747, 3173, 5064, 2903, 4271, 8095, 9849, 4161, 967, 7564, 2275, 1519, 7067, 7851, 385, 6816, 483, 7159, 7366, 9047, 610, 3374, 1719, 246, 747, 3273, 186, 5488, 144, 341, 6891, 8838, 667, 2515, 5916, 7720, 9878, 671, 3648, 7704, 8853, 7333, 8753, 6635, 1205, 1003, 5976, 6148, 7102, 2618, 6985, 9793, 2872, 2552, 9737, 8669, 5897, 3172, 9685, 1846, 9073, 2991, 8063, 8466, 6902, 2608, 1534, 748, 8715, 8739, 1902, 5131, 7857, 2386, 3702, 6792, 4644, 27, 8107, 9682, 8483, 8928, 4297, 7303, 1442, 2279, 8652, 5698, 5233, 8918, 4249, 2473, 8594, 8545, 4795, 8696, 7403,
		8515, 2413, 3871, 7203, 5968, 9400, 7353, 992, 8812, 8298, 2836, 4798, 2996, 6483, 434, 949, 2828, 407, 6307, 2962, 9273, 4897, 4585, 1577, 1564, 612, 4895, 2591, 272, 3355, 4659, 8937, 7243, 3717, 8825, 6098, 8675, 3339, 373, 9966, 1285, 6092, 9910, 5343, 1242, 4071, 9031, 9863, 9376, 3094, 8832, 2224, 6821, 5561, 3187, 8379, 2499, 4679, 6548, 7144, 6814, 4670, 9930, 7614, 5160, 6988, 774, 8676, 8324, 2207, 1272, 3876, 4829, 5891, 2245, 38, 7294, 5075, 1090, 3253, 2107, 637, 8681, 5198, 5413, 4537, 2051, 1958, 5291, 6316, 265, 7574, 5490, 1124, 6794, 8551, 3875, 8385, 4480, 4774, 5917, 1218, 4194, 8959, 6927, 8210, 5087,
		1827, 9618, 6428, 5744, 64, 7482, 2339, 640, 6944, 7120, 2643, 7999, 5221, 8194, 6513, 8995, 2714, 4033, 5718, 474, 9827, 1293, 2276, 1068, 5798, 3327, 5248, 2352, 8419, 7816, 3811, 5674, 7389, 4945, 6673, 5629, 4367, 7388, 2693, 8851, 8907, 8367, 3643, 7412, 3303, 5443, 3306, 2160, 9988, 2460, 3141, 7192, 9982, 7025, 5745, 6433, 6117, 4736, 2412, 2796, 8855, 9277, 4354, 2777, 6827, 905, 7307, 465, 761, 4276, 251, 7044, 5759, 7906, 866, 4816, 9839, 6060, 4949, 2076, 4561, 9126, 8175, 3184, 4086, 8413, 3562, 2653, 9689, 8608, 4012, 5959, 7538, 9313, 6922, 1104, 2902, 4536, 6448, 7623, 4239, 6021, 7558, 3932, 8938, 1731, 2476, 9332, 2286, 4062, 4722, 8650, 6725, 5694, 6422, 4413, 2931, 9271, 359, 8948, 3575, 7546, 5307, 1288, 8032, 9707, 5061, 3615, 9727, 8897, 7554, 6563, 5283, 4580, 1863, 2534, 294, 3497, 5074, 5716, 348, 5923, 7249, 8617, 1375, 6518, 5793, 9136, 9831,
		8971, 6636, 2364, 4183, 8015, 6680, 6637, 9505, 4863, 9128, 3629, 7372, 3538, 2041, 8798, 1199, 8936, 3590, 4936, 6671, 3148,
		167, 8007, 6883, 5135, 1646, 4318, 7347, 5533, 5377, 9038, 8469, 6568, 8800, 8361, 5986, 4998, 4266, 6215, 2602, 8641, 6626, 3784, 4805, 1570, 2359, 2895, 2977, 8835, 458, 8218, 2650, 9757, 5110, 7213, 8400, 3604, 5682, 2507, 6812, 5123, 6145, 6974, 1934, 7683, 2139, 8817, 2798, 1134, 5890, 9625, 2221, 5862, 2766, 7182, 2757, 7951, 9301, 4535, 5928, 5732, 7123, 2126, 5494, 6670, 7328, 9372, 4576, 6735, 2092, 4049, 9173, 6613, 8858, 9922, 4357, 7215, 2749, 8160, 6519, 4397, 5015, 7178, 4577, 6406, 838, 1447, 4361, 4835, 2801, 7441, 7689, 333, 7701, 7793, 2013, 5779, 7169, 611, 3234, 9444, 9723, 8224, 9192, 8915, 6262, 7114, 4542, 6890, 9407, 3894, 3704, 8405, 7063, 7382, 460, 9501, 5818, 8386, 1676, 6349, 4550, 9027, 227, 9159, 8660, 1282, 3523, 2266, 4250, 4125, 8730, 3815, 7786, 9760, 5446, 8391, 9455, 9169, 2966, 3524, 9020, 131, 1705, 8764, 4258, 9882, 1961, 681, 7927, 6087, 469, 1553, 7371, 2590, 8010, 6308, 155, 4335, 7122, 3334, 7026, 209, 5114, 4887, 508, 6083, 5225, 9810, 9555, 2795, 1226, 4292, 5218, 2842, 1332, 8743, 4053, 5741, 9987, 3014, 6555, 3899, 2189, 8596, 0, 7133, 1435, 3188, 6099, 4345, 9678, 5689, 9001, 2194, 1924, 6271, 93, 9477, 1968, 1354, 2624, 4122, 8011, 3774, 9174, 2028, 4142, 4384, 2186, 1891, 8189, 8373, 1597,
		4006, 7642, 1109, 5929, 5772, 9926, 7613, 8459, 6054, 84, 1566, 1842, 3119, 7436, 327, 3661, 3308, 9911, 8821, 1800, 4197, 2751, 8680, 5247, 8123, 29, 5517, 8747, 2913, 3866, 4563, 3340, 2347, 9848, 1904, 9495, 2556, 8550, 582, 6998, 5321, 1452, 5467,
		2444, 7725, 3554, 7037, 6991, 6119, 6372, 162, 1319, 5085, 9765, 5016, 1556, 6562, 2452, 3564, 3047, 2833, 7384, 2405, 2504, 3888, 4456, 4008, 5320, 8278, 1240, 728, 5703, 7596, 8399, 4619, 1423, 7575, 3073, 3159, 4609, 2614, 9860, 7378, 5142, 4248, 7247, 6247, 1819, 9387, 8957, 1412, 7405, 694, 9460, 2548, 5453, 7089, 1175, 2328, 1607, 5297, 7530, 9374, 1256, 1407, 6325, 7749, 9972, 7980, 6948, 1951, 8262, 416, 9096, 580, 8291, 5584, 463, 4371, 3975, 735, 6946, 7174, 3499, 2475, 5693, 7739, 6351, 6195, 8004, 3859, 3427, 499, 8348, 9934, 8740, 7956, 4508, 9298, 8939, 5544, 8627, 3557, 1025, 9034, 7051, 3087, 4939, 2290, 7314, 8114, 1492, 6669, 9755, 4337, 3685, 4997, 7799, 4229, 415, 2928, 3703, 976, 7377, 9699, 8687, 3761, 206, 6596, 5944, 8013, 2180, 7031, 5927, 296, 1230, 9, 2831, 9061, 1403, 8508, 2963, 9232, 2414, 8965, 869, 5856, 8468, 5887, 9287, 5226, 2830, 4738, 4645, 1884, 7244, 366, 7573, 6876, 8302, 3682, 4706, 3496, 914, 79, 6595, 8295, 3354, 8080, 8383, 5636, 4059, 8343, 1215, 2233, 2691, 6107, 2454, 7967, 2259, 313, 9005, 5070, 6905, 8883, 2604, 1614, 7433, 8012, 438, 7699, 5026, 8775, 380, 4789, 2154, 74, 5579, 2310, 3206, 3755, 8398, 5126, 7151, 7430, 4329, 7189, 6615, 397, 4002, 1080, 7386, 104, 7061, 8242, 7662, 9105, 3657, 821, 8879, 2399, 4268, 6688, 677, 1347, 4845, 3216, 1231, 1432, 9385, 9817, 4534, 3152, 6926, 5950, 7987, 2916, 6025, 7690, 684, 5356, 3264, 5622, 3617, 2385, 4478, 5762, 5777, 8447, 5364, 3832, 6522, 4914, 9734, 9004, 7970, 4710, 7198, 3632, 9336,
		9355, 5706, 7232, 3163, 3935, 6743, 9366, 8408, 8149, 4942, 7349, 3793, 2345, 797, 7989, 9345, 8514, 7585, 7600, 2465, 8028, 1000, 5809, 5646, 2240, 7808, 4395, 4926, 2694, 5214, 9117, 7528, 3097, 5641, 1518, 67, 5885, 8049, 4030, 7217, 6091, 4728, 6657, 918, 4634, 9731, 795, 4977, 3062, 3920, 2735, 4103, 744, 2372, 8565, 8365, 58, 1750, 6517, 4137, 4394, 3509, 3426, 6287, 6439, 8254, 2671, 5274, 7625, 3042, 1163, 1384, 6877, 5628, 6676, 7356, 9708, 6878, 2357, 1674, 1931, 4289, 338, 9672, 830, 5552, 9310, 427, 2898, 5869, 8849, 5808, 7204, 3545, 1349, 2791, 5032, 1401, 2600, 2209, 2783, 431, 9649, 7254, 2813, 7380, 5095,
		2955, 4707, 5450, 6402, 7768, 7898, 4629, 5675, 1030, 3495, 4023, 3595, 1531, 7100, 1836, 8309, 2669, 3120, 6703, 6017, 9286,
		981, 1929, 6958, 8822, 1105, 9306, 7186, 1500, 8633, 4281, 2166, 1430, 5357, 7058, 4709, 7028, 326, 4700, 3447, 6214, 5011, 9095, 6067, 3450, 9243, 915, 2442, 6874, 6015, 7555, 5567, 9050, 7424, 4218, 2543, 577, 1945, 28, 2458, 3679, 8427, 7753, 1417,
		6061, 3514, 8711, 7876, 114, 7948, 9439, 849, 241, 2508, 5980, 2172, 5238, 9320, 3820, 8863, 2270, 6625, 7497, 4375, 1551, 5707, 1730, 3939, 8454, 5287, 1352, 5033, 245, 3824, 7275, 8267, 3281, 3010, 8446, 7872, 6850, 7675, 2929, 7709, 4792, 1953, 4255, 8498, 6267, 3256, 4958, 7785, 4786, 2040, 7284, 8909, 5572, 8236, 8967, 9640, 1348, 1087, 362, 2381, 2046, 1928, 8921, 9998, 1049, 3111, 5266, 9974, 7606, 598, 1410, 5116, 116, 5763, 825, 4251, 8428, 764, 3766, 183, 9207, 2252, 1350, 4005, 9419, 1523, 4406, 1448, 7840, 9585, 8169, 899, 1345, 7862, 231, 2311, 9566, 3578, 5586, 5599, 6027, 5134, 5496, 4552, 5128, 9384, 9215,
		3366, 285, 9894, 4745, 6268, 4057, 8588, 5222, 1324, 7423, 4482, 7022, 1024, 8649, 3809, 5355, 7343, 5505, 713, 6413, 106, 8488, 7135, 3160, 8287, 4091, 9798, 1773, 2997, 1330, 6069, 1168, 9403, 8505, 7706, 703, 3171, 4882, 2651, 5183, 9139, 5431, 7141, 4647, 6815, 9015, 2135, 875, 2973, 4821, 826, 860, 6310, 3012, 125, 1680, 6188, 6365, 3325, 839, 5930, 1686, 4695, 9233, 5691, 7315, 4045, 6152, 1655, 7258, 8211, 794, 8522, 2008, 1255, 3842, 3204, 9575, 8200, 5781, 8215, 6410, 507, 4724, 6158, 8621, 9238, 4961, 1064, 6624, 5069, 6320, 5342, 2789, 2670, 9187, 3357, 1909, 2947, 1450, 3600, 4101, 1657, 9323, 6925, 7202, 4766, 922, 6805, 666, 6511, 8600, 3360, 4450, 1487, 5030, 4279, 2623, 9429, 933, 7928, 8052, 7002, 7455, 6834, 9240, 5841, 7166, 7766, 1994, 8970, 4794, 6173, 5043, 2064, 9862, 3622, 972, 916, 3850, 852, 7008, 2238, 9307, 3652, 5855, 6984, 1779, 5631, 6139, 8930, 408, 4532, 6438, 1456, 299, 2696, 7884, 4175, 8022, 8248, 6211, 790, 3494, 3580, 7048, 8610, 8848, 5994, 983, 8444, 6337, 5369, 547, 7712, 3390, 9157, 4990, 4704, 6471, 4907, 9058, 4358, 6976, 6556, 2514, 9730, 1475, 7195, 8741, 1645, 5310, 4148, 3201, 9790, 6143, 3041, 1204, 3735, 6762, 1557, 3411, 6774, 2081, 1127, 5792, 6978, 271, 6222, 9662, 4714, 2341, 602, 2241,
		9109, 9406, 698, 2337, 2885, 5042, 4256, 3955, 9367, 4872, 8868, 3452, 5163, 3810, 1162, 9595, 7435, 2523, 5313, 560, 7823, 6553, 4429, 5607, 8577, 2111, 7919, 4164, 5080, 7479, 9365, 9739, 539, 409, 2550, 8525, 9895, 9569, 7188, 2776, 3438, 8173, 3304, 2191, 2573, 1957, 3091, 4080, 2563, 3851, 2261, 4981, 5410, 2987, 753, 2943, 9132, 8869, 5237, 4269, 3769, 7649, 6359, 884,
		2190, 7988, 8645, 6893, 817, 6488, 5000, 6407, 8133, 3700, 8590, 952, 210, 2122, 9799, 8112, 1856, 6302, 3672, 6097, 8186, 1037, 1917, 4182, 2528, 9975, 707, 8265, 5860, 2099, 5801, 8755, 9655, 6106, 5997, 7913, 8152, 6525, 2984, 6187, 4230, 4838, 1376, 9836, 1692, 1851, 1868, 7633, 9019, 9897, 516, 4355, 630, 9198, 3618, 8246, 3709, 2215, 4946, 1837, 5449, 7259, 6127, 7565,
		4015, 9121, 2486, 297, 2371, 9089, 2410, 1043, 4046, 5044, 6295, 3974, 9393, 879, 7969, 2753, 6135, 2103, 9051, 8535, 7950, 9057, 6656, 7668, 1985, 8656, 5418, 5331, 506, 5796, 3818, 4857, 3531, 2082, 4668, 250, 6284, 1801, 6311, 2595, 5746, 8856, 4656, 676, 6491, 6505, 9658, 8328, 5717, 3254, 3733, 4978, 706, 6150, 5005, 1618, 3301, 6504, 3255, 2889, 5720, 2684, 7064, 7663,
		1001, 856, 404, 6128, 317, 4826, 5445, 8923, 7743, 7671, 6137, 9453, 8710, 163, 1895, 8772, 1561, 4952, 9319, 1528, 3550, 6702, 1302, 5271, 4130, 8726, 6029, 5990, 126, 3424, 7274, 571, 6787, 2510, 5979, 2227, 6748, 6797, 2077, 3827, 625, 7431, 1695, 5967, 7348, 2781, 1991, 2914, 1237, 4401, 6034, 9236, 4654, 6426, 4043, 8767, 7484, 2185, 6475, 7867, 3048, 7935, 3423, 3437, 5071, 6614, 8094, 850, 1539, 4392, 3314, 4519, 9932, 1510, 8700, 9510, 1097, 4599, 8231, 5837, 4473, 2584, 3142, 8384, 7502, 2055, 1568, 2006, 5795, 8864, 786, 2764, 3402, 1386, 7976, 7418, 3026, 6078, 9668, 9568, 254, 1369, 6754, 6283, 8148, 3348, 6101, 796, 2606, 6864, 6095, 260, 1462, 5324, 5191, 4730, 4441, 5045, 1696, 2958, 1232, 2715, 2317, 1606, 2101, 8312, 2073, 5813,
		1241, 1094, 8766, 379, 2719, 1441, 4178, 9370, 8745, 9300, 1071, 336, 157, 8317, 1546, 6549, 2156, 8318, 9694, 4811, 4514, 6293, 8598, 2457, 4960, 1427, 6236, 19, 5875, 1771, 3318, 8069, 3443, 4240, 500, 2027, 3440, 8654, 441, 1740, 8244, 6057, 331, 9919, 3468, 3317, 7933, 3408}, 187200, []int{100, 1872})
}

func test(a []int, p int, r []int) {
	t := twoproduct(a, p)
	fmt.Println(t)
	if len(t) == 0 {
		assert(len(t) == len(r))
	} else {
		assert(reflect.DeepEqual(t, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func twoproduct(a []int, p int) (r []int) {
	m := make(map[int]bool)
	for _, v := range a {
		u := 0
		if v != 0 {
			u = p / v
		}

		if m[u] && u*v == p {
			r = []int{u, v}
			break
		}
		m[v] = true
	}
	return
}
