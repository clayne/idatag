#pragma once

#include <QtWidgets/QTableView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QShortcut>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtCore/Qt>
#include <QtGui/QContextMenuEvent>

#include <ida.hpp>

#include "model.hpp"
#include "proxy.hpp"
#include "delegate.hpp"
#include "configuration.hpp"

class Idatag_view : public QWidget{
	Q_OBJECT
private:
	Idatag_model*		myModel;
	Idatag_proxy*		myProxy;
	Idatag_configuration* myConfiguration;
	QWidget*			parent;
	QTableView*			tb;
	QHeaderView*		hheader;
	QCheckBox*			cbox;
	QLineEdit*			tf;
	QLabel*				tfl;
	QShortcut*			sc_filter;
	QGridLayout*		layout;

	QWidget* wnd_filter_feeder;
	QGridLayout* feeder_filter_layout;
	QVBoxLayout* feeder_layout;
	QPushButton* btn_filter_feeder_ok;
	QPushButton* btn_filter_feeder_cancel;

public:
	Idatag_view(QWidget*, Idatag_model*, Idatag_configuration*);
	~Idatag_view();

	QTableView* get_Tb();

	void OnFilter_empty();
	void OnFilter_string();
	void OnFilter_feeder();
	void OnFilter_feeder_update();
	void OnFilter_feeder_show();
	void OnFilter_feeder_pass();

	void OnNavigate(const QModelIndex&);
	void OnSearch();
};

class Idatag_context : public QWidget {
	Q_OBJECT
private:
	action_activation_ctx_t* ctx;
	QGridLayout* menu_layout;
	QPushButton* btn_menu_ok;
	QPushButton* btn_menu_cancel;
	QLineEdit* tags_input;
	uint64_t rva;
	QLabel* lbl_rva;
	QLabel* lbl_name;

public:
	Idatag_context(action_activation_ctx_t*);

	void context_menu_add_tags();
	void context_menu_pass();
};