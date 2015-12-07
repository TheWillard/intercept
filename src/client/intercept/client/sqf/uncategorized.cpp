#include "uncategorized.hpp"
#include "client\pointers.hpp"
#include "common_helpers.hpp"


using namespace intercept::client::types;

namespace intercept {
	namespace sqf {
		namespace __uncategorized {
			std::vector<std::string> action_keys(std::string user_action_)
			{
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeys__string__ret__array, game_value_string(user_action_));
				std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);

				host::functions.free_value(&act_keys);
				return r_arr;
			}

			text action_keys_images(std::string user_action_)
			{
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysimages__string_array__ret__text, game_value_string(user_action_));
				return text(act_keys);
			}

			std::string action_keys_names(std::string user_action_)
			{
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, game_value_string(user_action_));
				std::string r_str = ((game_data_string *)act_keys.data)->get_string();

				host::functions.free_value(&act_keys);
				return r_str;
			}

			std::string action_keys_names(std::string user_action_, float max_keys_)
			{
				game_value_array<2> params({
					game_value_string(user_action_),
					game_value_number(max_keys_)
				});
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, params);
				std::string r_str = ((game_data_string *)act_keys.data)->get_string();

				host::functions.free_value(&act_keys);
				return r_str;
			}
			std::string action_keys_names(std::string user_action_, float max_keys_, std::string input_device_priority_)
			{
				game_value_array<3> params({
					game_value_string(user_action_),
					game_value_number(max_keys_),
					game_value_string(input_device_priority_)
				});
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnames__string_array__ret__string, params);
				std::string r_str = ((game_data_string *)act_keys.data)->get_string();

				host::functions.free_value(&act_keys);
				return r_str;
			}

			std::vector<std::string> action_keys_names_array(std::string user_action_)
			{
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, game_value_string(user_action_));
				std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);

				host::functions.free_value(&act_keys);
				return r_arr;
			}

			std::vector<std::string> action_keys_names_array(std::string user_action_, float max_keys_)
			{
				game_value_array<2> params({
					game_value_string(user_action_),
					game_value_number(max_keys_)
				});
				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, params);
				std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);

				host::functions.free_value(&act_keys);
				return r_arr;
			}
			std::vector<std::string> action_keys_names_array(std::string user_action_, float max_keys_, std::string input_device_priority_)
			{
				game_value_array<3> params({
					game_value_string(user_action_),
					game_value_number(max_keys_),
					game_value_string(input_device_priority_)
				});

				game_value act_keys = host::functions.invoke_raw_unary(client::__sqf::unary__actionkeysnamesarray__string_array__ret__array, params);
				std::vector<std::string> r_arr = __helpers::__convert_to_strings_vector(act_keys);

				host::functions.free_value(&act_keys);
				return r_arr;
			}

			void activate_addons(std::vector<std::string> &addons_)
			{
				game_value_array_dynamic<std::string, game_value_string> addons_arr(addons_);

				host::functions.invoke_raw_unary(client::__sqf::unary__activateaddons__array__ret__nothing, addons_arr);
			}

			/* potential namespace: camera */
			void add_cam_shake(float power_, float duration_, float frequency_)
			{
				game_value_array<3> params({
					game_value_number(power_),
					game_value_number(duration_),
					game_value_number(frequency_)
				});

				host::functions.invoke_raw_unary(client::__sqf::unary__addcamshake__array__ret__nothing, params);
			}

			/* potential namespace: items, inventory, campaign */
			void add_item_pool(std::string item_name_, float item_count_)
			{
				game_value_array<3> params({
					game_value_string(item_name_),
					game_value_number(item_count_)
				});

				host::functions.invoke_raw_unary(client::__sqf::unary__additempool__array__ret__nothing, params);
			}

			void add_magazine_pool(std::string mag_name_, float mag_count_)
			{
				game_value_array<3> params({
					game_value_string(mag_name_),
					game_value_number(mag_count_)
				});

				host::functions.invoke_raw_unary(client::__sqf::unary__addmagazinepool__array__ret__nothing, params);
			}

			/// @todo
			void add_to_remains_collector(std::vector<object> objects_)
			{
				//game_value_array_dynamic<object, game_value_object> objects_arr(objects_);
			}

			void ais_finish_heal(object wounded_, object medic_, bool medic_can_heal_)
			{
				game_value_array<3> params({
					wounded_,
					medic_,
					game_value_bool(medic_can_heal_)
				});

				host::functions.invoke_raw_unary(client::__sqf::unary__aisfinishheal__array__ret__nothing, params);
			}

			std::vector<object> all_mission_objects(std::string type_)
			{
				return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__allmissionobjects__string__ret__array, game_value_string(type_)));
			}

			std::vector<object> assigned_cargo(object veh_)
			{
				return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__assignedcargo__object__ret__array, veh_));
			}

			std::vector<std::string> assigned_items(object unit_)
			{
				return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__assigneditems__object__ret__array, unit_));
			}

			object attached_object(location loc_)
			{
				game_value ath_obj = host::functions.invoke_raw_unary(client::__sqf::unary__attachedobject__location__ret__object, loc_);
				return object(ath_obj);
			}

			std::vector<object> attached_objects(object obj_)
			{
				return __helpers::__convert_to_objects_vector(host::functions.invoke_raw_unary(client::__sqf::unary__attachedobjects__object__ret__array, obj_));
			}

			object attached_to(object obj_)
			{
				game_value ath_obj = host::functions.invoke_raw_unary(client::__sqf::unary__attachedto__object__ret__array, obj_);
				return object(ath_obj);
			}

			bool attack_enabled(object unit_)
			{
				return __helpers::__bool_unary_object(client::__sqf::unary__attackenabled__object_group__ret__bool, unit_);
			}

			bool attack_enabled(group group_)
			{
				game_value bool_ret = host::functions.invoke_raw_unary(client::__sqf::unary__attackenabled__object_group__ret__bool, group_);
				bool rv = ((game_data_bool *)bool_ret.data)->value;
				host::functions.free_value(&bool_ret);
				return rv;
			}

			std::vector<std::string> backpack_cargo(object box_)
			{
				return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__backpackcargo__object__ret__array, box_));
			}

			std::vector<std::string> backpack_items(object unit_)
			{
				return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__backpackitems__object__ret__array, unit_));
			}

			std::vector<std::string> backpack_magazines(object unit_)
			{
				return __helpers::__convert_to_strings_vector(host::functions.invoke_raw_unary(client::__sqf::unary__backpackmagazines__object__ret__array, unit_));
			}

			sqf::bounding_box bounding_box(object model_)
			{
				game_value input = host::functions.invoke_raw_unary(client::__sqf::unary__boundingbox__object__ret__array, model_);
				game_data_array* array_value = ((game_data_array *)input.data);

				sqf::bounding_box bb;

				float x_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[0].data)->number;
				float y_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[1].data)->number;
				float z_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[2].data)->number;
				bb.min = vector3(x_min, y_min, z_min);

				float x_max = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[0].data)->number;
				float y_max = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[1].data)->number;
				float z_max  = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[2].data)->number;
				bb.min = vector3(x_max, y_max, z_max);

				host::functions.free_value(&input);
				return bb;
			}

			sqf::bounding_box bounding_box_real(object model_)
			{
				game_value input = host::functions.invoke_raw_unary(client::__sqf::unary__boundingboxreal__object__ret__array, model_);
				game_data_array* array_value = ((game_data_array *)input.data);

				sqf::bounding_box bb;

				float x_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[0].data)->number;
				float y_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[1].data)->number;
				float z_min = ((game_data_number *)((game_data_array *)array_value->data[0].data)->data[2].data)->number;
				bb.min = vector3(x_min, y_min, z_min);

				float x_max = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[0].data)->number;
				float y_max = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[1].data)->number;
				float z_max = ((game_data_number *)((game_data_array *)array_value->data[1].data)->data[2].data)->number;
				bb.min = vector3(x_max, y_max, z_max);

				host::functions.free_value(&input);
				return bb;
			}

			vector3 bounding_center(object obj_)
			{
				game_value function_return_array = host::functions.invoke_raw_unary(client::__sqf::unary__boundingcenter__object__ret__array, obj_);
				float x = ((game_data_number *)((game_data_array *)function_return_array.data)->data[0].data)->number;
				float y = ((game_data_number *)((game_data_array *)function_return_array.data)->data[1].data)->number;
				float z = ((game_data_number *)((game_data_array *)function_return_array.data)->data[2].data)->number;
				host::functions.free_value(&function_return_array);
				return vector3(x, y, z);
			}


		}
	}
}