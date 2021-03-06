/*******************************************************************************
 * retroshare-gui/src/gui/Posted/PostedDialog.h                                *
 *                                                                             *
 * Copyright (C) 2013 by Robert Fernie       <retroshare.project@gmail.com>    *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Affero General Public License as              *
 * published by the Free Software Foundation, either version 3 of the          *
 * License, or (at your option) any later version.                             *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
 * GNU Affero General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Affero General Public License    *
 * along with this program. If not, see <https://www.gnu.org/licenses/>.       *
 *                                                                             *
 *******************************************************************************/


#ifndef MRK_POSTED_DIALOG_H
#define MRK_POSTED_DIALOG_H

#include "gui/gxs/GxsGroupFrameDialog.h"

#define IMAGE_POSTED ":/icons/png/posted.png"

class PostedDialog : public GxsGroupFrameDialog
{
	Q_OBJECT

public:
	/** Default Constructor */
	PostedDialog(QWidget *parent = 0);
	/** Default Destructor */
	~PostedDialog();

    virtual QIcon iconPixmap() const override { return QIcon(IMAGE_POSTED) ; } //MainPage
    virtual QString pageName() const override { return tr("Boards") ; } //MainPage
    virtual QString helpText() const override { return ""; } //MainPage

protected:
	virtual UserNotify *createUserNotify(QObject *parent) override;
    virtual QString getHelpString() const  override;
    virtual RetroShareLink::enumType getLinkType() override { return RetroShareLink::TYPE_POSTED; }
    virtual GroupFrameSettings::Type groupFrameSettingsType() override { return GroupFrameSettings::Posted; }

	void groupInfoToGroupItemInfo(const RsGxsGenericGroupData *groupData, GroupItemInfo &groupItemInfo) override;
	bool getGroupData(std::list<RsGxsGenericGroupData*>& groupInfo) override;
	bool getGroupStatistics(const RsGxsGroupId& groupId,GxsGroupStatistic& stat) override;

private:
	/* GxsGroupFrameDialog */
    virtual QString text(TextType type) override;
    virtual QString icon(IconType type) override;
    virtual QString settingsGroupName()  override{ return "PostedDialog"; }
    virtual GxsGroupDialog *createNewGroupDialog() override;
    virtual GxsGroupDialog *createGroupDialog(GxsGroupDialog::Mode mode, RsGxsGroupId groupId) override;
    virtual int shareKeyType() override;
    virtual GxsMessageFrameWidget *createMessageFrameWidget(const RsGxsGroupId &groupId) override;
    virtual RsGxsCommentService *getCommentService() override;
    virtual QWidget *createCommentHeaderWidget(const RsGxsGroupId &grpId, const RsGxsMessageId &msgId) override;
    virtual uint32_t requestGroupSummaryType() override { return GXS_REQUEST_TYPE_GROUP_DATA; } // request complete group data

	void handleEvent_main_thread(std::shared_ptr<const RsEvent> event);
    RsEventsHandlerId_t mEventHandlerId;
};

#endif
