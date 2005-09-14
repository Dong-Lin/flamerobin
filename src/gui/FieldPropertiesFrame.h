/*
  The contents of this file are subject to the Initial Developer's Public
  License Version 1.0 (the "License"); you may not use this file except in
  compliance with the License. You may obtain a copy of the License here:
  http://www.flamerobin.org/license.html.

  Software distributed under the License is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
  License for the specific language governing rights and limitations under
  the License.

  The Original Code is FlameRobin (TM).

  The Initial Developer of the Original Code is Milan Babuskov.

  Portions created by the original developer
  are Copyright (C) 2004 Milan Babuskov.

  All Rights Reserved.

  $Id$

  Contributor(s): Nando Dessena
*/

#ifndef FIELDPROPERTIESFRAME_H
#define FIELDPROPERTIESFRAME_H
//-----------------------------------------------------------------------------
#include <wx/wx.h>
#include <wx/image.h>
#include <wx/statline.h>

#include "core/Observer.h"
#include "gui/BaseFrame.h"
#include "metadata/column.h"
#include "metadata/table.h"
//-----------------------------------------------------------------------------
class FieldPropertiesFrame: public BaseFrame, public Observer {
public:
    enum {
        ID_button_edit_domain = 102,
        ID_button_ok = 103,
        ID_button_cancel = 104,
        ID_radio_new = 111,
        ID_radio_existing = 112,
        ID_textctrl_generatorname = 114,
        ID_textctrl_fieldname = 117,
        ID_ch_generators = 115,
        ID_ch_charset = 118,
        ID_cb_trigger = 110,
        ID_ch_domains = 116,
        ID_ch_datatypes = 119
    };

    void OnButtonEditDomainClick(wxCommandEvent &event);
    void OnButtonOkClick(wxCommandEvent &event);
    void OnButtonCancelClick(wxCommandEvent &event);

    void OnRadioNewClick(wxCommandEvent &event);
    void OnRadioExistingClick(wxCommandEvent &event);
    void OnCbTriggerClick(wxCommandEvent &event);
    void OnChGeneratorsClick(wxCommandEvent &event);
    void OnChDomainsClick(wxCommandEvent &event);
    void OnChCharsetClick(wxCommandEvent &event);
    void OnChDatatypesClick(wxCommandEvent &event);
    void OnTextctrlGeneratornameChange(wxCommandEvent &event);
    void OnTextctrlFieldnameChange(wxCommandEvent &event);

    // Database is required so that domains, charsets, generators can be loaded
    FieldPropertiesFrame(wxWindow* parent, int id, wxString title, Table *table, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);
    void setField(Column *field);
    void setProperties();

private:
    void loadCollations(wxString desired);
    void updateSqlWindow();
    void updateEditBoxes();
    Column *fieldM;     // needed when field is edited
    Table *tableM;          // needed when new field is added

    // begin wxGlade: FieldPropertiesFrame::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    void removeSubject(Subject* subject);
    void updateDomainInfo(wxString domain);
    bool getDomainInfo(wxString domain, wxString& type, wxString& size, wxString& scale, wxString& charset);
    void update();

    // begin wxGlade: FieldPropertiesFrame::attributes
    wxStaticText* label_8;
    wxTextCtrl* textctrl_fieldname;
    wxStaticText* label_1;
    wxChoice* ch_domains;
    wxButton* button_edit_domain;
    wxStaticText* label_2;
    wxChoice* ch_datatypes;
    wxStaticText* label_3;
    wxTextCtrl* textctrl_size;
    wxStaticText* label_4;
    wxTextCtrl* textctrl_scale;
    wxCheckBox* cb_notnull;
    wxStaticText* label_5;
    wxChoice* ch_charset;
    wxStaticText* label_6;
    wxChoice *ch_collate;
    wxStaticLine* static_line_1;
    wxStaticText* label_7;
    wxRadioButton* radio_new;
    wxTextCtrl* textctrl_generatorname;
    wxRadioButton* radio_existing;
    wxChoice* ch_generators;
    wxCheckBox* cb_trigger;
    wxTextCtrl* textctrl_sql;
    wxButton* button_ok;
    wxButton* button_cancel;
    wxPanel* panel_1;
    // end wxGlade

    DECLARE_EVENT_TABLE()
    virtual const wxString getName() const;
};
//-----------------------------------------------------------------------------
#endif // FIELDPROPERTIESFRAME_H
