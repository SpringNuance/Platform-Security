# vim: sw=4:ts=4:et


%define relabel_files() \
restorecon -R /usr/local/bin/password_manager; \

%define selinux_policyver 0.0.0

Name:   password_manager_selinux
Version:	1.0
Release:	1%{?dist}
Summary:	SELinux policy module for password_manager

Group:	System Environment/Base		
License:	GPLv2+	
# This is an example. You will need to change it.
URL:		http://HOSTNAME
Source0:	password_manager.pp
Source1:	password_manager.if
Source2:	password_manager_selinux.8


Requires: policycoreutils, libselinux-utils
Requires(post): selinux-policy-base >= %{selinux_policyver}, policycoreutils
Requires(postun): policycoreutils
BuildArch: noarch

%description
This package installs and sets up the  SELinux policy security module for password_manager.

%install
install -d %{buildroot}%{_datadir}/selinux/packages
install -m 644 %{SOURCE0} %{buildroot}%{_datadir}/selinux/packages
install -d %{buildroot}%{_datadir}/selinux/devel/include/contrib
install -m 644 %{SOURCE1} %{buildroot}%{_datadir}/selinux/devel/include/contrib/
install -d %{buildroot}%{_mandir}/man8/
install -m 644 %{SOURCE2} %{buildroot}%{_mandir}/man8/password_manager_selinux.8
install -d %{buildroot}/etc/selinux/targeted/contexts/users/


%post
semodule -n -i %{_datadir}/selinux/packages/password_manager.pp
if /usr/sbin/selinuxenabled ; then
    /usr/sbin/load_policy
    %relabel_files

fi;
exit 0

%postun
if [ $1 -eq 0 ]; then
    semodule -n -r password_manager
    if /usr/sbin/selinuxenabled ; then
       /usr/sbin/load_policy
       %relabel_files

    fi;
fi;
exit 0

%files
%attr(0600,root,root) %{_datadir}/selinux/packages/password_manager.pp
%{_datadir}/selinux/devel/include/contrib/password_manager.if
%{_mandir}/man8/password_manager_selinux.8.*


%changelog
* Sat Jan 21 2023 YOUR NAME <YOUR@EMAILADDRESS> 1.0-1
- Initial version

