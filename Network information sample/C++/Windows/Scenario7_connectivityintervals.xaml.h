//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Scenario7_connectivityintervals.xaml.h
// Declaration of the ProfileConnectivityIntervals class
//

#pragma once

using namespace Windows::Networking;
using namespace Windows::Networking::Connectivity;
using namespace Windows::Foundation;
using namespace Platform;
using namespace Windows::Foundation::Collections;

#include "pch.h"
#include "Scenario7_connectivityintervals.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace NetworkInformationApi
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class ProfileConnectivityIntervals sealed
        {
        public:
            ProfileConnectivityIntervals();
    
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        private:
            MainPage^ rootPage;
            // This is the profile that we are getting usage information for
            ConnectionProfile^ internetConnectionProfile;

            // These are set from the UI and passed to the GetConnectivityIntervals and GetNetworkUsage functions
            NetworkUsageStates networkUsageStates;
            DateTime startTime;
            DateTime endTime;

            // This is used to print DateTimes in a human-readable format
            Windows::Globalization::DateTimeFormatting::DateTimeFormatter^ formatter;

            void ProfileConnectivityIntervalsButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            String^ PrintConnectivityIntervals(IVectorView<ConnectivityInterval^>^ connectivityIntervals);
            String^ PrintConnectivityInterval(ConnectivityInterval^ connectivityInterval);
            DateTime GetDateTimeFromUi(Windows::UI::Xaml::Controls::DatePicker^ datePicker, Windows::UI::Xaml::Controls::TimePicker^ timePicker);
            TriStates GetTriStatesFromUi(Windows::UI::Xaml::Controls::ComboBox^ triStatesComboBox);
        };
    }
}