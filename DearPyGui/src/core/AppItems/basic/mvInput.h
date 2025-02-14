#pragma once

#include <string>
#include <array>
#include "mvItemRegistry.h"
#include "mvContext.h"
#include "mvModule_DearPyGui.h"

//-----------------------------------------------------------------------------
// Widget Index
//
//     * mvInputText
//     * mvInputInt
//     * mvInputIntMulti
//     * mvInputFloat
//     * mvInputFloatMulti
//
//-----------------------------------------------------------------------------

namespace Marvel {

    //-----------------------------------------------------------------------------
    // mvInputText
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvInputText, MV_ITEM_DESC_DEFAULT, StorageValueTypes::String, 1);
    class mvInputText : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvInputText, add_input_text)
            MV_NO_COMMANDS
            MV_DEFAULT_PARENTS
            MV_DEFAULT_CHILDREN
            MV_NO_CONSTANTS

            MV_SET_STATES(
                MV_STATE_HOVER |
                MV_STATE_ACTIVE |
                MV_STATE_FOCUSED |
                MV_STATE_CLICKED |
                MV_STATE_VISIBLE |
                MV_STATE_EDITED |
                MV_STATE_ACTIVATED |
                MV_STATE_DEACTIVATED |
                MV_STATE_DEACTIVATEDAE |
                MV_STATE_RECT_MIN |
                MV_STATE_RECT_MAX |
                MV_STATE_RECT_SIZE |
                MV_STATE_CONT_AVAIL
            );

    public:

        explicit mvInputText(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;

        // values
        void setDataSource(mvUUID dataSource) override;
        void* getValue() override { return &_value; }
        PyObject* getPyValue() override;
        void setPyValue(PyObject* value) override;

    private:

        mvRef<std::string>  _value = CreateRef<std::string>("");
        std::string         _disabled_value = "";
        std::string         _hint;
        bool                _multiline = false;
        ImGuiInputTextFlags _flags = 0;
        ImGuiInputTextFlags _stor_flags = 0;

    };

    //-----------------------------------------------------------------------------
    // mvInputInt
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvInputInt, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int, 1);
    class mvInputInt : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvInputInt, add_input_int)
            MV_NO_COMMANDS
            MV_DEFAULT_PARENTS
            MV_DEFAULT_CHILDREN
            MV_NO_CONSTANTS

            MV_SET_STATES(
                MV_STATE_HOVER |
                MV_STATE_ACTIVE |
                MV_STATE_FOCUSED |
                MV_STATE_CLICKED |
                MV_STATE_VISIBLE |
                MV_STATE_EDITED |
                MV_STATE_ACTIVATED |
                MV_STATE_DEACTIVATED |
                MV_STATE_DEACTIVATEDAE |
                MV_STATE_RECT_MIN |
                MV_STATE_RECT_MAX |
                MV_STATE_RECT_SIZE |
                MV_STATE_CONT_AVAIL
            );

    public:

        explicit mvInputInt(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;

        // values
        void setDataSource(mvUUID dataSource) override;
        void* getValue() override { return &_value; }
        PyObject* getPyValue() override;
        void setPyValue(PyObject* value) override;

    private:

        mvRef<int>          _value = CreateRef<int>(0);
        int                 _disabled_value = 0;
        int                 _step = 1;
        int                 _step_fast = 100;
        int                 _min = 0;
        int                 _max = 100;
        bool                _min_clamped = false;
        bool                _max_clamped = false;
        ImGuiInputTextFlags _flags = 0;
        ImGuiInputTextFlags _stor_flags = 0;
        int                 _last_value = 0;

    };
      
    //-----------------------------------------------------------------------------
    // mvInputIntMulti
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvInputIntMulti, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int4, 1);
    class mvInputIntMulti : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvInputIntMulti, add_input_intx)
        MV_NO_COMMANDS
        MV_DEFAULT_PARENTS
        MV_DEFAULT_CHILDREN
        MV_NO_CONSTANTS

        MV_SET_STATES(
            MV_STATE_HOVER |
            MV_STATE_ACTIVE |
            MV_STATE_FOCUSED |
            MV_STATE_CLICKED |
            MV_STATE_VISIBLE |
            MV_STATE_EDITED |
            MV_STATE_ACTIVATED |
            MV_STATE_DEACTIVATED |
            MV_STATE_DEACTIVATEDAE |
            MV_STATE_RECT_MIN |
            MV_STATE_RECT_MAX |
            MV_STATE_RECT_SIZE |
            MV_STATE_CONT_AVAIL
        );

    public:

        explicit mvInputIntMulti(mvUUID uuid);
    
        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;

        // value
        void setDataSource(mvUUID dataSource) override;
        void* getValue() override { return &_value; }
        PyObject* getPyValue() override;
        void setPyValue(PyObject* value) override;

    private:
        mvRef<std::array<int, 4>> _value = CreateRef<std::array<int, 4>>(std::array<int, 4>{0, 0, 0, 0});
        int                       _disabled_value[4]{};
        int                       _min = 0;
        int                       _max = 100;
        bool                      _min_clamped = false;
        bool                      _max_clamped = false;
        ImGuiInputTextFlags       _flags = 0;
        ImGuiInputTextFlags       _stor_flags = 0;
        std::array<int, 4>        _last_value = { 0, 0, 0, 0 };
        int                       _size = 4;
        
    };

    //-----------------------------------------------------------------------------
    // mvInputFloat
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvInputFloat, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float, 1);
    class mvInputFloat : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvInputFloat, add_input_float)
            MV_NO_COMMANDS
            MV_DEFAULT_PARENTS
            MV_DEFAULT_CHILDREN
            MV_NO_CONSTANTS

            MV_SET_STATES(
                MV_STATE_HOVER |
                MV_STATE_ACTIVE |
                MV_STATE_FOCUSED |
                MV_STATE_CLICKED |
                MV_STATE_VISIBLE |
                MV_STATE_EDITED |
                MV_STATE_ACTIVATED |
                MV_STATE_DEACTIVATED |
                MV_STATE_DEACTIVATEDAE |
                MV_STATE_RECT_MIN |
                MV_STATE_RECT_MAX |
                MV_STATE_RECT_SIZE |
                MV_STATE_CONT_AVAIL
            );

    public:

        explicit mvInputFloat(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;

        // values
        void setDataSource(mvUUID dataSource) override;
        void* getValue() override { return &_value; }
        PyObject* getPyValue() override;
        void setPyValue(PyObject* value) override;

    private:

        mvRef<float>        _value = CreateRef<float>(0.0f);
        float               _disabled_value = 0.0f;
        float               _min = 0.0f;
        float               _max = 100.0f;
        bool                _min_clamped = false;
        bool                _max_clamped = false;
        std::string         _format = "%.3f";
        float               _step = 0.1f;
        float               _step_fast = 1.0f;
        ImGuiInputTextFlags _flags = 0;
        ImGuiInputTextFlags _stor_flags = 0;
        float               _last_value = 0.0f;

    };
        
    //-----------------------------------------------------------------------------
    // mvInputFloatMulti
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvInputFloatMulti, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float4, 1);
    class mvInputFloatMulti : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvInputFloatMulti, add_input_floatx)
        MV_NO_COMMANDS
        MV_DEFAULT_PARENTS
        MV_DEFAULT_CHILDREN
        MV_NO_CONSTANTS

        MV_SET_STATES(
            MV_STATE_HOVER |
            MV_STATE_ACTIVE |
            MV_STATE_FOCUSED |
            MV_STATE_CLICKED |
            MV_STATE_VISIBLE |
            MV_STATE_EDITED |
            MV_STATE_ACTIVATED |
            MV_STATE_DEACTIVATED |
            MV_STATE_DEACTIVATEDAE |
            MV_STATE_RECT_MIN |
            MV_STATE_RECT_MAX |
            MV_STATE_RECT_SIZE |
            MV_STATE_CONT_AVAIL
        );

    public:

        explicit mvInputFloatMulti(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;
        
       // value
        void setDataSource(mvUUID dataSource) override;
        void* getValue() override { return &_value; }
        PyObject* getPyValue() override;
        void setPyValue(PyObject* value) override;
        
    private:

        mvRef<std::array<float, 4>> _value = CreateRef<std::array<float, 4>>(std::array<float, 4>{0.0f, 0.0f, 0.0f, 0.0f});
        float                       _disabled_value[4]{};
        float                       _min = 0.0f;
        float                       _max = 100.0f;
        bool                        _min_clamped = false;
        bool                        _max_clamped = false;
        std::string                 _format = "%.3f";
        ImGuiInputTextFlags         _flags = 0;
        ImGuiInputTextFlags         _stor_flags = 0;
        std::array<float, 4>        _last_value = { 0.0f, 0.0f, 0.0f, 0.0f };
        int                         _size = 4;
    };

}
