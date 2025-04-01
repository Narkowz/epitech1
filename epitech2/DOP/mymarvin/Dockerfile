FROM epitechcontent/epitest-docker AS data
WORKDIR /data
COPY . /data

FROM jenkins/jenkins:lts
USER root
RUN jenkins-plugin-cli --plugins \
configuration-as-code \
job-dsl \
role-strategy   \
github  \
cloudbees-folder    \
ws-cleanup  \
instance-identity   \
script-security \
structs

COPY --chown=jenkins:jenkins --from=data /data /var/jenkins_home

ENV CASC_JENKINS_CONFIG=/var/jenkins_home/my_marvin.yml
ENV JAVA_OPTS="-Djenkins.install.runSetupWizard=false"

ENV USER_CHOCOLATEEN_PASSWORD="4242"
ENV USER_VAUGIE_G_PASSWORD="4242"
ENV USER_I_DONT_KNOW_PASSWORD="4242"
ENV USER_NASSO_PASSWORD="4242"

VOLUME /var/jenkins_home
EXPOSE 8080

USER jenkins
